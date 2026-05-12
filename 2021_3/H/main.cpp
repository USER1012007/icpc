#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> colores(k);
  vector<int> pos(n);

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp >> pos[i];

    colores[pos[i] - 1].push_back(tmp);
  }

  for (int i = 0; i < k; i++) {
    sort(colores[i].begin(), colores[i].end(), greater<int>());
  }

  int last = 0;
  int current = 0;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    current = colores[pos[i] - 1][colores[pos[i] - 1].size() - 1];
    if (current < last) {
      flag = false;
      break;
    }
    last = current;
    colores[pos[i] - 1].pop_back();
  }

  cout << (flag ? 'Y' : 'N');
}

int main() {
  fast_io();
  solve();
  return 0;
}
