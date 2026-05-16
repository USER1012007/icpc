#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 200005; // Número máximo de nodos

std::vector<int> adj[MAXN];

int dp_con[MAXN];
int dp_sin[MAXN];

// DFS que calcula el DP de abajo hacia arriba (Post-order traversal)
void dfs_tree_dp(int u, int p) {
  dp_con[u] = 1; // Si tomo a 'u', ya llevo 1 nodo
  dp_sin[u] = 0; // Si no tomo a 'u', llevo 0 nodos

  for (int v : adj[u]) {
    if (v == p)
      continue; // Evitamos regresar al nodo padre

    // Primero calculamos el DP de los hijos (ir hasta las hojas del árbol)
    dfs_tree_dp(v, u);

    // Al regresar del hijo, acumulamos las transiciones en el padre 'u'
    dp_con[u] += dp_sin[v];
    dp_sin[u] += std::max(dp_con[v], dp_sin[v]);
  }
}

// Función para limpiar el árbol entre casos de prueba
void clear_tree(int total_nodos) {
  for (int i = 1; i <= total_nodos; i++) {
    adj[i].clear();
    dp_con[i] = 0;
    dp_sin[i] = 0;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int nodos = 5;
  clear_tree(nodos);

  std::vector<std::pair<int, int>> aristas = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

  for (auto &edge : aristas) {
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_tree_dp(1, 0);

  int respuesta = std::max(dp_con[1], dp_sin[1]);

  std::cout << "El tamano del Conjunto Independiente Maximo es: " << respuesta
            << "\n";

  return 0;
}
