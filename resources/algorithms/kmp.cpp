#include <iostream>
#include <string>
#include <vector>

const int MAXM = 100005; // Longitud máxima que puede tener el PATRÓN
int kmp_link[MAXM];

// 1. Precomputar la tabla de fallos para el patrón 'p'
void kmp_build(const std::string &p) {
  int m = p.size();
  kmp_link[0] = -1;
  int j = -1;

  for (int i = 0; i < m;) {
    while (j >= 0 && p[i] != p[j]) {
      j = kmp_link[j];
    }
    i++;
    j++;
    kmp_link[i] = j;
  }
}

// 2. Buscar el patrón 'p' dentro del texto 't'
void kmp_search(const std::string &t, const std::string &p) {
  int n = t.size();
  int m = p.size();
  int j = 0;

  for (int i = 0; i < n; i++) {
    while (j >= 0 && t[i] != p[j]) {
      j = kmp_link[j];
    }
    j++;
    if (j == m) {
      // ¡Match encontrado! Aquí modificas lo que necesitas hacer con el índice
      j = kmp_link[j];
    }
  }
}

int main() {
  std::string texto = "ababaaaba";
  std::string patron = "aba";

  kmp_build(patron);
  kmp_search(texto, patron);

  return 0;
}
