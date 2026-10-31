#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll tri = ((n + 1) * (n + 2) / 2) % MOD; // (n+1)(n+2) ≤ ~1e18, fits
    ll res = tri * ((k + 1) % MOD) % MOD;   // < 1e18, fits
    cout << res << '\n';
  }
  return 0;
}
