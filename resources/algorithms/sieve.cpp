#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 1000005; // Ajustar según el límite del problema

int spf[MAXN];          // Factor Primo Menor (Smallest Prime Factor)
int phi[MAXN];          // Función de Euler (coprimos con n)
int mu[MAXN];           // Función de Möbius
int cnt_div[MAXN];      // Cantidad de divisores
int pi[MAXN];           // Función contadora de primos (prefix sums)
vector<int> primes;     // Lista de números primos encontrados

void build_sieve() {
  phi[1] = 1;
  mu[1] = 1;
  cnt_div[1] = 1;   
  vector<int> e(MAXN, 0); // Auxiliar para contar divisores: exponente del menor factor primo 
                          
  for (int i = 2; i < MAXN; ++i) {
    if (spf[i] == 0) { // Si es 0, i es primo 
      spf[i] = i;
      primes.push_back(i);
      phi[i] = i - 1;
      mu[i] = -1;
      cnt_div[i] = 2;
      e[i] = 1;
    }

    for (int p : primes) {
      if (p > spf[i] || (ll)i * p >= MAXN) break;
        spf[i * p] = p;
        if (i % p == 0) {
          // p ya divide a i (no son coprimos)
          phi[i * p] = phi[i] * p;
          mu[i * p] = 0;
          e[i * p] = e[i] + 1;
          cnt_div[i * p] = cnt_div[i] / (e[i] + 1) * (e[i * p] + 1);
          break;
        } else {
          // p e i son coprimos
          phi[i * p] = phi[i] * (p - 1);
          mu[i * p] = -mu[i];
          e[i * p] = 1;
          cnt_div[i * p] = cnt_div[i] * 2;
        }
    }
  }
    
  // Precalcular pi(x) - Función contadora de primos
  for (int i = 1; i < MAXN; i++) {
    pi[i] = pi[i-1] + (spf[i] == i);
  }
}

// Factorización rápida en O(log N)
vector<pair<int, int>> get_factorization(int n) {
  vector<pair<int, int>> factors;
  while (n > 1) {
    int p = spf[n];
    int count = 0;
    while (n % p == 0) {
      n /= p;
      count++;
    }

    factors.push_back({p, count});
  }

  return factors;
}
