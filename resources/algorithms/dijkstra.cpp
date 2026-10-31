#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n + 1); // {vecino, peso}
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w}); // quitar si dirigido
  }

  int s = 1;
  vector<ll> dist(n + 1, INF);
  vector<int> par(n + 1, -1); // para reconstruir camino
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue; // entrada vieja
    for (auto [v, w] : g[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        par[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  // dist[v] == INF -> inalcanzable
  // camino a t:
  int t = n;
  if (dist[t] == INF) {
    cout << -1;
    return 0;
  }
  vector<int> path;
  for (int v = t; v != -1; v = par[v])
    path.push_back(v);
  reverse(path.begin(), path.end());
  for (int v : path)
    cout << v << " ";
}
