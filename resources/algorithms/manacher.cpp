#include <algorithm>
#include <iostream>
#include <string>

const int MAXN = 200005; // Tamaño máximo del string ORIGINAL
int P[2 * MAXN + 3];     // El string transformado mide el doble, por eso el 2*

// Encuentra todos los palíndromos en 's'
void manacher(const std::string &s) {
  // 1. Transformar el string: "aba" -> "^#a#b#a#$"
  std::string t = "^";
  for (char c : s) {
    t += "#";
    t += c;
  }
  t += "#$";

  int m = t.size();
  int c = 0, r = 0;

  for (int i = 1; i < m - 1; i++) {
    int i_mirror = 2 * c - i;

    if (r > i) {
      P[i] = std::min(r - i, P[i_mirror]);
    } else {
      P[i] = 0;
    }

    // Expandir el palíndromo centrado en i
    while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
      P[i]++;
    }

    // Actualizar el centro si nos pasamos del borde derecho actual
    if (i + P[i] > r) {
      c = i;
      r = i + P[i];
    }
  }
}

bool es_palindromo(int l, int r) {
  int t_l = 2 * l + 2;
  int t_r = 2 * r + 2;
  int centro = (t_l + t_r) / 2;
  int longitud = r - l + 1;
  return P[centro] >= longitud;
}

int main() {
  std::string s = "racecar";
  manacher(s);

  // Verificar subcadenas en O(1)
  // "aceca" está desde el índice 1 al 5 en "racecar"
  if (es_palindromo(1, 5)) {
    std::cout << "El substring es palindromo\n";
  }

  return 0;
}
