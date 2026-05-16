typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;

ll fact[MAX], invFact[MAX], invNum[MAX];;

ll power(ll x, ll n){
  ll ans = 1;

  while(n){
    if(n & 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }

  return ans % MOD;
}

void precalc() {
  fact[0] = 1;
  invNum[1] = 1;
  for (int i = 1; i < MAX; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
    if (i > 1) invNum[i] = (MOD - MOD / i) * invNum[MOD % i] % MOD;
  }
  
  invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
  for (int i = MAX - 2; i >= 0; --i) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }
}

ll nCr(int n, int r){ // Combinaciones cuando el orden no imoporta
  if(r < 0 || r > n) return 0;
  return (((invFact[r] * invFact[n-r]) % MOD) * fact[n]) % MOD;
}

ll nCr_large(ll n, int r) { // Para n grande 10^18 y r pequeño 10^6
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r; // propiedad de simetría
    
    ll num = 1;
    for (int i = 0; i < r; ++i) {
        num = (num * ((n - i) % MOD)) % MOD;
    }
    return (num * invFact[r]) % MOD;
}

ll nPr(int n, int r) { // Permutaciones
    if (r < 0 || r > n) return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}

ll stars_and_bars(int n, int k) { // Combinaciones con repetición
    if (n == 0 && k == 0) return 1;
    return nCr(n + k - 1, k);
}

/** Probabilidad */
#include <vector>
using namespace std;

// Inverso multiplicativo modular (requiere que MOD sea primo)
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// Divide dos enteros bajo módulo: P / Q -> (P * Q^-1) % MOD
ll modDivide(ll p, ll q) {
    p = (p % MOD + MOD) % MOD;
    q = (q % MOD + MOD) % MOD;
    return (p * modInverse(q)) % MOD;
}

typedef vector<vector<ll>> matrix;

// Multiplicación de matrices bajo módulo
matrix multiply(const matrix& A, const matrix& B) {
    int r = A.size(), c = B[0].size(), m = A[0].size();
    matrix C(r, vector<ll>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int k = 0; k < m; ++k) {
            for (int j = 0; j < c; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Exponenciación binaria de matrices
matrix matrixPower(matrix A, ll p) {
    int n = A.size();
    matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1; // Matriz Identidad

    while (p) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}
