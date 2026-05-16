#include <algorithm>
#include <iostream>
#include <string>

const int MAXN = 200005; // Tamaño máximo del string
int z[MAXN];             // Arreglo Z global

void build_z(const std::string &s) {
  int n = s.size();

  // Inicializar el arreglo Z
  for (int i = 0; i < n; i++)
    z[i] = 0;

  int l = 0, r = 0;

  for (int i = 1; i < n; i++) {
    // Si i está dentro de la Z-box actual, copiamos el valor ya calculado
    if (i <= r) {
      z[i] = std::min(r - i + 1, z[i - l]);
    }

    // Intentamos expandir el match de forma lineal
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }

    // Si encontramos una coincidencia que se extiende más allá de r,
    // actualizamos la Z-box
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

int main() {
  // Ejemplo de cómo calcula el arreglo Z
  std::string s = "aaaaa";
  build_z(s);

  std::cout << "i\tChar\tZ[i]\n";
  for (int i = 0; i < s.size(); i++) {
    std::cout << i << "\t" << s[i] << "\t" << z[i] << "\n";
  }

  std::string texto = "ababaaaba";
  std::string patron = "aba";

  std::string fusion = patron + "$" + texto;

  build_z(fusion);

  int tam_patron = patron.size();

  for (int i = tam_patron + 1; i < fusion.size(); i++) {
    if (z[i] == tam_patron) {
      int indice_original = i - (tam_patron + 1);
      std::cout << "Patron encontrado en el indice: " << indice_original
                << "\n";
    }
  }

  return 0;
}
