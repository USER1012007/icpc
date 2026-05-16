#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;
const char BASE_CHAR = 'a';

// MAX_NODES debe ser la suma de las longitudes de todos los patrones + 1
const int MAX_NODES = 200005;

// Estructura del Trie en matrices planas
int trie[MAX_NODES][ALPHABET_SIZE];
int fail[MAX_NODES];      // Enlace de falla (equivalente al link de KMP)
int out_words[MAX_NODES]; // Cuenta cuántos patrones terminan exactamente en
                          // este nodo
int node_count = 1;       // El nodo 0 es la raíz

// 1. Inserta un patrón en el Trie tradicional
void insert_pattern(const std::string &s) {
  int u = 0;
  for (char c : s) {
    int idx = c - BASE_CHAR;
    if (trie[u][idx] == 0) {
      // Inicializar las transiciones del nuevo nodo a 0 (limpieza)
      std::memset(trie[node_count], 0, sizeof(trie[node_count]));
      fail[node_count] = 0;
      out_words[node_count] = 0;

      trie[u][idx] = node_count++;
    }
    u = trie[u][idx];
  }
  out_words[u]++; // Marcamos que un patrón termina en el nodo 'u'
}

// 2. Construye los enlaces de falla usando un BFS (Automata)
void build_automation() {
  std::queue<int> q;

  // Primero procesamos los hijos directos de la raíz (nodo 0)
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (trie[0][i] != 0) {
      fail[trie[0][i]] = 0;
      q.push(trie[0][i]);
    }
  }

  // BFS para propagar los fallos
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < ALPHABET_SIZE; i++) {
      int v = trie[u][i];
      if (v != 0) {
        // El fallo del hijo es el estado al que te lleva el caracter 'i'
        // desde el fallo del padre
        fail[v] = trie[fail[u]][i];

        out_words[v] += out_words[fail[v]];

        q.push(v);
      } else {
        trie[u][i] = trie[fail[u]][i];
      }
    }
  }
}

int search_in_text(const std::string &text) {
  int u = 0;
  int total_matches = 0;

  for (char c : text) {
    int idx = c - BASE_CHAR;
    u = trie[u][idx];
    total_matches += out_words[u];
  }
  return total_matches;
}

// Limpieza rápida para reutilizar entre casos de prueba
void clear_aho() {
  std::memset(trie[0], 0, sizeof(trie[0]));
  fail[0] = 0;
  out_words[0] = 0;
  node_count = 1;
}

int main() {
  clear_aho(); // Siempre limpiar al inicio de un caso de prueba

  // Tus patrones a buscar
  std::vector<std::string> palabras = {"he", "she", "his", "hers"};
  for (const auto &p : palabras) {
    insert_pattern(p);
  }

  // Construye los enlaces eficientes
  build_automation();

  std::string texto = "ahishers";
  int matches = search_in_text(texto);

  std::cout << "Total de ocurrencias encontradas: " << matches << "\n";
  // Salida esperada: 4 (encuentra "his", "she", "he", "hers")

  return 0;
}
