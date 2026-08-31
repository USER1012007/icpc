#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  int c, v, sum_c = 0, sum_v = 0;
  int levels[n];

  for (int i = 0; i < n; i++) {

    cin >> c >> v;

    sum_c += c;
    sum_v += v;

    if (sum_c > sum_v) {
      levels[i] = 1;
    } else if (sum_c < sum_v) {
      levels[i] = -1;
    } else {
      levels[i] = 0;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int qi;
    cin >> qi;
    if (levels[qi - 1] == 1) {
      cout << "COMPRA\n";
    } else if (levels[qi - 1] == -1) {
      cout << "VENDA\n";
    } else {
      cout << "NEUTRO\n";
    }
  }
}

int main() {
  fast_io();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
