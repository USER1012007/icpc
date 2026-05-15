#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int m, n;
  cin >> m >> n;
  int arrm[m], arrn[n];
  int pm = 0, pn[n];

  for (int i = 0; i < m; i++) {
    cin >> arrm[i];
    pm += arrm[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> arrn[i];
    pn[i] = arrn[i];
    if (i > 0)
      pn[i] += pn[i - 1];
  }

  int counter = 0;

  for (int i = 0; i < n - m + 1; i++) {
    int mod = arrn[i] - arrm[0];
    if (mod < 0) {
      mod = arrm[0] - arrn[i];
    }
    int sumrange = (pn[i + m]);
    if (i > 0) {
      sumrange -= pn[i - 1];
    }
    if (sumrange % mod == pm % mod) {
      counter++;
    }
  }
  cout << counter;
}

int main() {
  fast_io();
  int t;
  solve();
  return 0;
}
