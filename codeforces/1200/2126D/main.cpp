#include <cstdio>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;
typedef long long ll;

void solve() {
  ll n, k;
  cin >> n >> k;
  set<tuple<ll, ll, ll>> s;

  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    s.insert({a, b, c});
  }
  for (const auto &[a, b, c] : s) {
    k = (k >= a && k <= b && c > k) ? c : k;
  }
  cout << k << "\n";
}

int main(int argc, char *argv[]) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
