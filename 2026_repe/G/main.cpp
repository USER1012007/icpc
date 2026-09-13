#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> Vu(n);
  vector<int> Vv(n);
  vector<int> Vc(n);

  for (int i = 0; i < n; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    Vu.push_back(u);
    Vv.push_back(v);
    Vc.push_back(cost);
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
