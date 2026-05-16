#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 200005; // Número máximo de nodos
const int LOGN = 20;     // 2^19 es 524,288 (suficiente para MAXN = 200,000)

std::vector<int> adj[MAXN]; // Lista de adyacencia global
int depth[MAXN];            // depth[u] guarda el nivel/profundidad del nodo u
int up[MAXN][LOGN];         // Tabla de Binary Lifting

void dfs_lca(int u, int p, int d) {
  depth[u] = d;
  up[u][0] = p;

  for (int i = 1; i < LOGN; i++) {
    if (up[u][i - 1] != -1) {
      up[u][i] = up[up[u][i - 1]][i - 1];
    } else {
      up[u][i] = -1;
    }
  }

  for (int v : adj[u]) {
    if (v != p) {
      dfs_lca(v, u, d + 1);
    }
  }
}

int get_lca(int u, int v) {
  if (depth[u] < depth[v]) {
    std::swap(u, v);
  }

  int diff = depth[u] - depth[v];
  for (int i = LOGN - 1; i >= 0; i--) {
    if ((diff >> i) & 1) {
      u = up[u][i];
    }
  }

  if (u == v)
    return u;

  for (int i = LOGN - 1; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}

void clear_lca(int total_nodos) {
  for (int i = 1; i <= total_nodos; i++) {
    adj[i].clear();
    for (int j = 0; j < LOGN; j++) {
      up[i][j] = -1;
    }
  }
}

int get_kth_ancestor(int u, int k) {
  for (int i = LOGN - 1; i >= 0; i--) {
    if ((k >> i) & 1) {
      u = up[u][i];
      if (u == -1)
        break; // Nos salimos del árbol
    }
  }
  return u;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int nodos = 7;
  clear_lca(nodos);

  // Aristas de ejemplo para un árbol binario perfecto de 3 niveles:
  //       1
  //      / \
  //     2   3
  //    / \ / \
  //   4  5 6  7
  std::vector<std::pair<int, int>> aristas = {{1, 2}, {1, 3}, {2, 4},
                                              {2, 5}, {3, 6}, {3, 7}};

  for (auto &edge : aristas) {
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_lca(1, -1, 0);

  // Consultas de ejemplo
  std::cout << "LCA de 4 y 5: " << get_lca(4, 5) << "\n";  // Salida: 2
  std::cout << "LCA de 4 && 6: " << get_lca(4, 6) << "\n"; // Salida: 1
  std::cout << "LCA de 3 y 7: " << get_lca(3, 7) << "\n";  // Salida: 3

  return 0;
}
