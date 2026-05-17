#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

struct DSU {
  vector<int> parent, sz;
  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n, 1);
  }
  int find(int i) { return (parent[i] == i) ? i : parent[i] = find(parent[i]); }
  bool join(int i, int j) {
    int root_i = find(i), root_j = find(j);
    if (root_i != root_j) {
      if (sz[root_i] < sz[root_j])
        swap(root_i, root_j);
      parent[root_j] = root_i;
      sz[root_i] += sz[root_j];
      return true;
    }
    return false;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  DSU dsu(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    dsu.join(a, b);
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
