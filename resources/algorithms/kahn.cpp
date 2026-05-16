#include <vector>
#include <queue>

using namespace std;

bool topSort(const vector<vector<int>>& adj, vector<int>& order) {
    int n = adj.size();
    vector<int> in_degree(n, 0);
    
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) in_degree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    order.clear();
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }

    return (order.size() == n); // Retorna falso si hay un ciclo (no se procesaron todos)
}
