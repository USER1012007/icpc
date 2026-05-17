#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Tu función original impecable
bool topSort(const vector<vector<int>> &adj, vector<int> &order) {
  int n = adj.size();
  vector<int> in_degree(n, 0);

  for (int u = 0; u < n; u++) {
    for (int v : adj[u])
      in_degree[v]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (in_degree[i] == 0)
      q.push(i);
  }

  order.clear();
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);

    for (int v : adj[u]) {
      in_degree[v]--;
      if (in_degree[v] == 0)
        q.push(v);
    }
  }

  return (order.size() == n);
}

int main() {
  vector<string> materias = {
      "Introduccion a la Programacion", // 0
      "Estructuras de Datos",           // 1
      "Prog. Orientada a Objetos",      // 2
      "Bases de Datos",                 // 3
      "Desarrollo Web",                 // 4
      "Proyecto Final"                  // 5
  };

  int n = materias.size();
  vector<vector<int>> adj(n);

  // Construimos el grafo (u -> v significa "u es prerrequisito de v")
  adj[0].push_back(1); // Intro -> Estructuras de Datos
  adj[0].push_back(2); // Intro -> POO
  adj[1].push_back(3); // Estructuras de Datos -> Bases de Datos
  adj[2].push_back(4); // POO -> Desarrollo Web
  adj[3].push_back(4); // Bases de Datos -> Desarrollo Web
  adj[4].push_back(5); // Desarrollo Web -> Proyecto Final

  vector<int> orden_materias;

  cout << "--- Planificador de Horarios Universitarios ---\n" << endl;

  if (topSort(adj, orden_materias)) {
    cout << "¡Ruta de aprendizaje valida encontrada!\n" << endl;
    for (int i = 0; i < orden_materias.size(); i++) {
      int id_materia = orden_materias[i];
      cout << i + 1 << ". " << materias[id_materia] << endl;
    }
  } else {
    cout << "Error: ¡Hay una dependencia circular en las materias!" << endl;
  }

  return 0;
}
