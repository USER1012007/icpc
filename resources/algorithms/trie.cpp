#include <cstring>
#include <iostream>
#include <string>
#include <vector>

template <int ALPHA = 26, char BASE = 'a'> struct Trie {
  struct Node {
    int next[ALPHA];
    int pass = 0;
    int end = 0;

    Node() { std::memset(next, -1, sizeof(next)); }
  };

  std::vector<Node> nodes;

  Trie() { nodes.emplace_back(); }

  void clear() {
    nodes.clear();
    nodes.emplace_back();
  }

  void reserve(int total_expected_nodes) {
    nodes.reserve(total_expected_nodes + 1);
  }

  void insert(const std::string &s) {
    int u = 0;
    nodes[u].pass++;
    for (char c : s) {
      int idx = c - BASE;
      if (nodes[u].next[idx] == -1) {
        nodes[u].next[idx] = nodes.size();
        nodes.emplace_back();
      }
      u = nodes[u].next[idx];
      nodes[u].pass++;
    }
    nodes[u].end++;
  }

  int count_words(const std::string &s) const {
    int u = 0;
    for (char c : s) {
      int idx = c - BASE;
      if (nodes[u].next[idx] == -1)
        return 0;
      u = nodes[u].next[idx];
    }
    return nodes[u].end;
  }

  int count_prefix(const std::string &s) const {
    int u = 0;
    for (char c : s) {
      int idx = c - BASE;
      if (nodes[u].next[idx] == -1)
        return 0;
      u = nodes[u].next[idx];
    }
    return nodes[u].pass;
  }
};

Trie<> trie;

int main() {
  trie.reserve(100000);

  trie.insert("apple");
  trie.insert("app");

  std::cout << trie.count_words("app") << "\n";  // Salida: 1
  std::cout << trie.count_prefix("app") << "\n"; // Salida: 2 ("apple" y "app")
  std::cout << trie.count_words("banana") << "\n";

  //// Para manejar cadenas numéricas (0-9)
  Trie<10, '0'> trie_numerico;

  // Para manejar caracteres en mayúscula (A-Z)
  Trie<26, 'A'> trie_mayusculas;

  // Para un set extendido de caracteres ASCII imprimibles
  Trie<95, ' '> trie_ascii;
}
