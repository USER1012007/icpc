#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 2005;      // Número máximo de NODOS
const long long INF = 1e18; // Infinito seguro para long long

struct Arista {
  int u, v, peso;
};

std::vector<Arista> aristas; // Lista plana con TODAS las aristas del grafo
long long dist[MAXN];        // Arreglo global de distancias
int parent[MAXN];            // Arreglo para reconstruir el camino

// Retorna true si todo sale bien, o false si detecta un ciclo negativo
bool bellman_ford(int src, int total_nodos) {
  for (int i = 1; i <= total_nodos; i++) {
    dist[i] = INF;
    parent[i] = -1;
  }

  dist[src] = 0;

  for (int i = 1; i <= total_nodos - 1; i++) {
    bool hubo_cambio = false;

    for (const auto &edge : aristas) {
      if (dist[edge.u] != INF && dist[edge.u] + edge.peso < dist[edge.v]) {
        dist[edge.v] = dist[edge.u] + edge.peso;
        parent[edge.v] = edge.u;
        hubo_cambio = true;
      }
    }

    if (!hubo_cambio)
      break;
  }

  for (const auto &edge : aristas) {
    if (dist[edge.u] != INF && dist[edge.u] + edge.peso < dist[edge.v]) {
      return false; // Se detectó un ciclo negativo alcanzable desde el origen
    }
  }

  return true; // Caminos mínimos calculados con éxito
}

void clear_bellman() { aristas.clear(); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int nodos = 4, conexiones = 4;
  clear_bellman();

  // Grafo con peso negativo pero SIN ciclo negativo:
  // 1 -> 2 (peso 4)
  // 1 -> 3 (peso 5)
  // 3 -> 2 (peso -2)
  // 2 -> 4 (peso 3)
  aristas.push_back({1, 2, 4});
  aristas.push_back({1, 3, 5});
  aristas.push_back({3, 2, -2});
  aristas.push_back({2, 4, 3});

  int origen = 1;

  if (bellman_ford(origen, nodos)) {
    std::cout << "Nodo\tDistancia minima desde " << origen << "\n";
    for (int i = 1; i <= nodos; i++) {
      std::cout << i << "\t";
      if (dist[i] == INF)
        std::cout << "INF\n";
      else
        std::cout << dist[i] << "\n";
    }
  } else {
    std::cout << "¡El grafo contiene un ciclo negativo!\n";
  }

  return 0;
}
