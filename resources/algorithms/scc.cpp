#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 200005; // Número máximo de nodos

std::vector<int> adj[MAXN]; // Lista de adyacencia del grafo dirigido

int dfs_num[MAXN];   // Tiempo de descubrimiento de cada nodo
int dfs_low[MAXN];   // El nodo más bajo alcanzable desde el subárbol
bool in_stack[MAXN]; // Marca si el nodo está actualmente en la pila
int timer = 0;       // Contador global para el tiempo de descubrimiento

std::vector<int>
    st;            // Pila plana para mantener los nodos de la componente actual
int scc_count = 0; // Contador de cuántas SCCs hemos encontrado
int scc_id[MAXN]; // scc_id[u] guarda a qué ID de componente pertenece el nodo u

void tarjan_dfs(int u) {
  dfs_num[u] = dfs_low[u] = ++timer;
  st.push_back(u);
  in_stack[u] = true;

  for (int v : adj[u]) {
    // Caso 1: Nodo no visitado todavía
    if (dfs_num[v] == 0) {
      tarjan_dfs(v);
      dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
    }
    // Caso 2: El nodo ya está en la pila (arista de retroceso o cruzada hacia
    // la misma SCC)
    else if (in_stack[v]) {
      dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
    }
  }

  // Si u es la raíz de una SCC, procedemos a extraer todos sus nodos de la pila
  if (dfs_low[u] == dfs_num[u]) {
    scc_count++;
    while (true) {
      int v = st.back();
      st.pop_back();
      in_stack[v] = false;

      scc_id[v] = scc_count; // Asignamos el ID de la componente al nodo

      // Aquí puedes procesar el nodo de la SCC actual o guardarlo
      if (u == v)
        break;
    }
  }
}

// Inicializa y ejecuta Tarjan en todo el grafo
void find_sccs(int total_nodos) {
  timer = 0;
  scc_count = 0;
  st.clear();
  for (int i = 1; i <= total_nodos; i++) {
    dfs_num[i] = 0;
    dfs_low[i] = 0;
    in_stack[i] = false;
    scc_id[i] = 0;
  }

  // Corremos el DFS en todos los nodos por si el grafo está desconectado
  for (int i = 1; i <= total_nodos; i++) {
    if (dfs_num[i] == 0) {
      tarjan_dfs(i);
    }
  }
}

// Limpieza para múltiples casos de prueba
void clear_tarjan(int total_nodos) {
  for (int i = 1; i <= total_nodos; i++) {
    adj[i].clear();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int nodos = 5;
  clear_tarjan(nodos);

  // Grafo dirigido de ejemplo:
  // 1 -> 2 -> 3 -> 1  (Ciclo/SCC 1: Nodos 1, 2, 3)
  // 3 -> 4 -> 5       (Nodos 4 y 5 son SCCs individuales independientes)
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(1);
  adj[3].push_back(4);
  adj[4].push_back(5);

  find_sccs(nodos);

  std::cout << "Total de componentes (SCCs) encontradas: " << scc_count << "\n";

  std::cout << "Nodo\tID de su SCC\n";
  for (int i = 1; i <= nodos; i++) {
    std::cout << i << "\t" << scc_id[i] << "\n";
  }

  return 0;
}
