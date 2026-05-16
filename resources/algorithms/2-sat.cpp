#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 100005; // Máximo número de VARIABLES individuales

std::vector<int> adj[2 * MAXN];

int dfs_num[2 * MAXN], dfs_low[2 * MAXN], scc_id[2 * MAXN];
bool in_stack[2 * MAXN];
std::vector<int> st;
int timer = 0, scc_count = 0;

int assignment[MAXN];

void tarjan(int u) {
  dfs_num[u] = dfs_low[u] = ++timer;
  st.push_back(u);
  in_stack[u] = true;

  for (int v : adj[u]) {
    if (dfs_num[v] == 0) {
      tarjan(v);
      dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
    } else if (in_stack[v]) {
      dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
    }
  }

  if (dfs_low[u] == dfs_num[u]) {
    scc_count++;
    while (true) {
      int v = st.back();
      st.pop_back();
      in_stack[v] = false;
      scc_id[v] = scc_count;
      if (u == v)
        break;
    }
  }
}

void add_implication(int u, int v) { adj[u].push_back(v); }

void add_clause_or(int a, bool a_is_true, int b, bool b_is_true,
                   int total_vars) {
  int node_a = a_is_true ? a : a + total_vars;
  int node_not_a = a_is_true ? a + total_vars : a;

  int node_b = b_is_true ? b : b + total_vars;
  int node_not_b = b_is_true ? b + total_vars : b;

  add_implication(node_not_a, node_b);
  add_implication(node_not_b, node_a);
}

bool solve_2sat(int total_vars) {
  int total_nodos = 2 * total_vars;

  timer = scc_count = 0;
  st.clear();
  for (int i = 1; i <= total_nodos; i++) {
    dfs_num[i] = 0;
    in_stack[i] = false;
  }

  for (int i = 1; i <= total_nodos; i++) {
    if (dfs_num[i] == 0)
      tarjan(i);
  }

  // 1. Verificar si hay contradicciones
  for (int i = 1; i <= total_vars; i++) {
    if (scc_id[i] == scc_id[i + total_vars]) {
      return false; // x y ~x están en la misma SCC -> Imposible
    }
  }

  // Tarjan encuentra las SCCs en orden topológico inverso.
  // Para elegir un valor válido sin contradicciones, seleccionamos el nodo
  // que aparezca MÁS TARDE en el orden topológico (es decir, menor scc_id).
  for (int i = 1; i <= total_vars; i++) {
    if (scc_id[i] < scc_id[i + total_vars]) {
      assignment[i] = 1; // Variable i es Verdadera
    } else {
      assignment[i] = 0; // Variable i es Falsa
    }
  }

  return true;
}

void clear_2sat(int total_vars) {
  for (int i = 1; i <= 2 * total_vars; i++) {
    adj[i].clear();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int variables = 3;
  clear_2sat(variables);

  // 1. Añadimos las restricciones (cláusulas)
  // Clausula 1: (x1 es verdadera O x2 es verdadera)
  add_clause_or(1, true, 2, true, variables);

  // Clausula 2: (x1 es FALSA O x3 es verdadera)
  add_clause_or(1, false, 3, true, variables);

  // Clausula 3: (x2 es verdadera O x3 es FALSA)
  add_clause_or(2, true, 3, false, variables);

  // 2. Resolver el sistema
  if (solve_2sat(variables)) {
    std::cout << "¡El sistema tiene solucion!\n";
    for (int i = 1; i <= variables; i++) {
      std::cout << "Variable x" << i << " = "
                << (assignment[i] ? "TRUE" : "FALSE") << "\n";
    }
  } else {
    std::cout << "El sistema NO es compatible (SATISFIABLE).\n";
  }

  return 0;
}
