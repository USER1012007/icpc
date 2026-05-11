#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), l(n), r(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  l[0] = a[0];
  for (int i = 1; i < n; i++) {
    l[i] = gcd(l[i - 1], a[i]);
  }
  r[n - 1] = a[n - 1];
  for (int i = n - 1; i--;) {
    r[i] = gcd(r[i + 1], a[i]);
  }

  ll ans = l[n - 1];

  for (int i = 1; i < n - 1; i++) {
    ans += min(l[i], r[i]);
  }
  cout << ans;
}

int main() {
  fast_io();
  solve();
  return 0;
}
