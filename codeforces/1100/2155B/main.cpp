#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  long n, k;
  cin >> n >> k;
  if (k == n * n - 1) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  for (long row = 0; row < n; row++) {
    if (k >= n) {
      cout << string(n, 'U') << '\n';
      k -= n;
    } else if (k == n - 1) {
      cout << (string(k, 'U') + "D") << '\n';
      k = 0;
    } else {
      cout << (string(k, 'U') + string(n - 1 - k, 'R')) + "L" << '\n';
      k = 0;
    }
  }
}

int main() {
  fast_io();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
