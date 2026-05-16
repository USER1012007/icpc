#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int MAXN = 200005; // Tamaño máximo del string + 1

std::string S;
int N;
int sa[MAXN];   // Suffix Array: sa[i] guarda el índice de inicio del i-ésimo
                // sufijo ordenado
int rn_k[MAXN]; // Rank actual de los sufijos
int tmp[MAXN];  // Arreglo temporal para el Radix Sort
int lcp[MAXN];  // LCP[i]: Prefijo común más largo entre sa[i] y sa[i-1]

// Counting Sort auxiliar para el Radix Sort
void counting_sort(int k) {
  int max_val = std::max(300, N); // 300 cubre el alfabeto ASCII básico
  std::vector<int> head(max_val, 0);

  for (int i = 0; i < N; i++) {
    int idx = (sa[i] + k < N) ? rn_k[sa[i] + k] : 0;
    head[idx]++;
  }

  int sum = 0;
  for (int i = 0; i < max_val; i++) {
    int t = head[i];
    head[i] = sum;
    sum += t;
  }

  for (int i = 0; i < N; i++) {
    int idx = (sa[i] + k < N) ? rn_k[sa[i] + k] : 0;
    tmp[head[idx]++] = sa[i];
  }

  for (int i = 0; i < N; i++) {
    sa[i] = tmp[i];
  }
}

// 1. Construye el Suffix Array en O(N log N)
void build_suffix_array(const std::string &input_str) {
  S = input_str + "$"; // Se añade un centinela menor a cualquier caracter
  N = S.size();

  for (int i = 0; i < N; i++) {
    sa[i] = i;
    rn_k[i] = S[i];
  }

  for (int k = 1; k < N; k <<= 1) {
    counting_sort(k); // Ordena por la segunda mitad del bloque
    counting_sort(0); // Ordena por la primera mitad del bloque

    tmp[sa[0]] = 0;
    int r = 0;
    for (int i = 1; i < N; i++) {
      // Si la pareja de rangos actuales es igual a la anterior, mantienen el
      // mismo rank
      if (rn_k[sa[i]] == rn_k[sa[i - 1]] &&
          ((sa[i] + k < N && sa[i - 1] + k < N)
               ? rn_k[sa[i] + k] == rn_k[sa[i - 1] + k]
               : false)) {
        tmp[sa[i]] = r;
      } else {
        tmp[sa[i]] = ++r;
      }
    }
    for (int i = 0; i < N; i++) {
      rn_k[i] = tmp[i];
    }
    if (rn_k[sa[N - 1]] == N - 1)
      break; // Optimización: si todos ya tienen ranks únicos, termina antes
  }
}

// 2. Construye el arreglo LCP en O(N) (Algoritmo de Kasai)
void build_lcp() {
  int k = 0;
  lcp[0] = 0;
  for (int i = 0; i < N; i++) {
    if (rn_k[i] == 0) {
      k = 0;
      continue;
    }
    int j =
        sa[rn_k[i] - 1]; // Sufijo inmediatamente anterior en el Suffix Array
    while (i + k < N && j + k < N && S[i + k] == S[j + k]) {
      k++;
    }
    lcp[rn_k[i]] = k;
    if (k > 0)
      k--;
  }
}

int main() {
  std::string s = "banana";

  build_suffix_array(s);
  build_lcp();

  // Mostrar resultados (empezamos desde 1 para ignorar el centinela '$')
  std::cout << "i\tSA\tLCP\tSuffix\n";
  std::cout << "------------------------------------\n";
  for (int i = 1; i < N; i++) {
    std::cout << i << "\t" << sa[i] << "\t" << lcp[i] << "\t" << S.substr(sa[i])
              << "\n";
  }

  int max_len = 0;
  int idx = 0;
  for (int i = 1; i < N; i++) {
    if (lcp[i] > max_len) {
      max_len = lcp[i];
      idx = sa[i];
    }
  }

  return 0;
}
