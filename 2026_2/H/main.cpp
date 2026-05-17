#include <iostream>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  ll n;
  cin >> n;
  ll r[n];
  ll k[n];

  for (ll i = 0; i < n; i++) {
    cin >> r[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> k[i];
  }

  ll T = 0;
  ll t_men = r[0] + k[0];
  ll count_men = 1;
  ll to = 0;

  for (ll i = 1; i < n; i++) {
    ll t = r[i] + k[i];

    if (r[i] > r[i - 1] && count_men > 0) {
      if (to + t_men > T)
        T = to + t_men;
      count_men = 0;
      t_men = 0;
    }

    if (r[i] > r[i - 1]) {
      to = T;
      T += t;
    } else {
      int tmp = t + count_men;
      if (tmp > t_men) {
        t_men = tmp;
      }
      count_men++;
    }
    if ((i == n - 1) && (to + t_men > T)) {
      T = to + t_men;
    }
  }

  cout << T;
}

int main() {
  fast_io();
  solve();
  return 0;
}
