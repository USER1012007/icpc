#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 200005; // Número máximo de nodos en el grafo
const long long INF =
    1e18; // Usamos un infinito grande para evitar desbordamientos con long long

std::vector<std::pair<int, int>> adj[MAXN];

long long dist[MAXN]; // Arreglo global de distancias cortas
int parent[MAXN];     // Arreglo opcional para reconstruir el camino mínimo

void dijkstra(int src, int total_nodos) {
  for (int i = 1; i <= total_nodos; i++) {
    dist[i] = INF;
    parent[i] = -1;
  }

  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>>
      pq;

  // 2. Configurar el nodo origen
  dist[src] = 0;
  pq.push({0, src});

  // 3. Bucle principal del algoritmo
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    // OPTIMIZACIÓN CRUCIAL: Si ya encontramos un camino más corto a 'u',
    // ignoramos este estado viejo/obsoleto de la cola.
    if (d > dist[u])
      continue;

    // Revisar todos los vecinos de 'u'
    for (auto &edge : adj[u]) {
      int v = edge.first;
      int peso = edge.second;

      // Relajación de la arista
      if (dist[u] + peso < dist[v]) {
        dist[v] = dist[u] + peso;
        parent[v] = u; // Guardamos de dónde venimos para reconstruir el camino
        pq.push({dist[v], v});
      }
    }
  }
}

// Función para limpiar el grafo entre diferentes casos de prueba
void clear_graph(int total_nodos) {
  for (int i = 1; i <= total_nodos; i++) {
    adj[i].clear();
  }
}

void imprimir_camino(int destino) {
  if (dist[destino] == INF) {
    std::cout << "No hay camino disponible.\n";
    return;
  }
  std::vector<int> camino;
  for (int v = destino; v != -1; v = parent[v]) {
    camino.push_back(v);
  }
  std::reverse(camino.begin(), camino.end());

  for (int nodo : camino)
    std::cout << nodo << " ";
  std::cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int nodos = 5, aristas = 6;
  clear_graph(nodos);

  std::vector<std::vector<int>> ejemplo_aristas = {
      {1, 2, 4}, {1, 3, 2}, {2, 3, 1}, {2, 4, 5}, {3, 4, 8}, {4, 5, 3}};

  for (auto &edge : ejemplo_aristas) {
    int u = edge[0], v = edge[1], peso = edge[2];
    adj[u].push_back({v, peso});
    // Si el grafo fuera NO dirigido, descomentas la siguiente línea:
    // adj[v].push_back({u, peso});
  }

  int origen = 1;
  dijkstra(origen, nodos);

  std::cout << "Nodo\tDistancia desde el nodo " << origen << "\n";
  for (int i = 1; i <= nodos; i++) {
    std::cout << i << "\t";
    if (dist[i] == INF)
      std::cout << "INF\n";
    else
      std::cout << dist[i] << "\n";
  }

  return 0;
}
