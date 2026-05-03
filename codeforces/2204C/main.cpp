#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {

  ll a, b, c, m;
  cin >> a >> b >> c >> m;

  ll aIbIc = m / lcm(a, lcm(b, c));

  ll aIb = m / lcm(a, b) - aIbIc;
  ll aIc = m / lcm(a, c) - aIbIc;
  ll bIc = m / lcm(b, c) - aIbIc;

  ll na = m / a - aIbIc - aIb - aIc;
  ll nb = m / b - aIbIc - aIb - bIc;
  ll nc = m / c - aIbIc - aIc - bIc;

  ll res1 = na * 6 + aIb * 3 + aIc * 3 + aIbIc * 2;
  ll res2 = nb * 6 + aIb * 3 + bIc * 3 + aIbIc * 2;
  ll res3 = nc * 6 + aIc * 3 + bIc * 3 + aIbIc * 2;

  cout << res1 << ' ' << res2 << ' ' << res3 << endl;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
