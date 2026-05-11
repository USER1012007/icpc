#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int &i : a)
    cin >> i;
  int ans = 0;
  int limit = n >> 1;
  for (int i = 0; i < limit; i++) {
    ans = gcd(ans, abs(a[i] - a[n - 1 - i]));
  }
  cout << ans << '\n';
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
