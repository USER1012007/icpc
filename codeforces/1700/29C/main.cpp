#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

map<ll, vector<ll>> grafo;
ll n;

void dfs(ll node, ll adj) {
  cout << node << ' ';
  for (auto neighbor : grafo[node])
    if (neighbor != adj)
      dfs(neighbor, node);
}

void solve() {
  cin >> n;
  set<ll> visited;

  for (int i = 0; i < n; i++) {
    ll u, v;
    cin >> u >> v;

    grafo[u].push_back(v);
    grafo[v].push_back(u);

    visited.insert(u);
    visited.insert(v);
  }

  for (auto i : visited) {
    if (grafo[i].size() == 1) {
      dfs(i, -1);
      return;
    }
  }
}

int main() {
  fast_io();
  ll t = 1;

  while (t--) {
    solve();
  }
  return 0;
}
