#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  if (n & 1)
    n--;
  cout << n / 2 << '\n';
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
