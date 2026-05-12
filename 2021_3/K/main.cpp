#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int t, d, m;
  bool sePuede = false;
  cin >> t >> d >> m;
  int arrm[m + 1];
  int dif[m + 2];

  dif[0] = 0;
  dif[m + 1] = d;

  if (d >= t && m == 0) {
    sePuede = true;
  }

  for (int i = 1; i <= m; i++) {
    cin >> arrm[i];

    dif[i] = arrm[i];
    if (i > 1)
      dif[i] = dif[i] - arrm[i - 1];

    if (dif[i] >= t)
      sePuede = true;
  }

  dif[m + 1] -= arrm[m];

  if (dif[m + 1] >= t) {
    sePuede = true;
  }
  cout << (sePuede ? 'Y' : 'N');
}

int main() {
  fast_io();
  solve();
  return 0;
}
