/**
//  Dijkstra en O(E logV)
**/
#include <vector>
#include <queue>

using namespace std;
const long long INF = 1e18;

// adj[u] guarda parejas de {vecino, peso}
void dijkstra(int start, const vector<vector<pair<int, int>>>& adj, vector<long long>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    // priority_queue ordena de menor a mayor usando 'greater'
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {distancia, nodo}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Ignorar estados viejos desactualizados

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
