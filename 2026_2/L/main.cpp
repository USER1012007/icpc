#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define MAX 1e7
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool is_prime(ll n) {
  if (n <= 1)
    return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void solve() {
  ll n;
  cin >> n;
  ll arrn[n];
  vector<ll> sol;
  for (ll i = 0; i < n; i++) {
    ll tmp1;
    ll counter = 0;

    cin >> tmp1;

    for (ll j = 1; j <= tmp1; j++) {
      ll tmp = j * j + 1;
      if (is_prime(tmp)) {
        counter++;
      }
    }

    cout << counter << '\n';
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
