#include <iostream>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  ll m, n;
  cin >> m >> n;
  ll M[m], N[n];
  for (ll i = 0; i < m; i++)
    cin >> M[i];
  for (ll i = 0; i < n; i++)
    cin >> N[i];

  ll difM[m - 1];
  for (ll i = 0; i < m - 1; i++)
    difM[i] = M[i] - M[i + 1];

  ll subarrs = n - m + 1;
  ll output = 0;

  for (ll i = 0; i < subarrs; i++) {

    for (ll j = 0; j < m - 1; j++) {

      if (N[i + j] - N[i + 1 + j] != difM[j])
        break;
      if (j == m - 2)
        output++;
    }
  }

  cout << output;
}

int main() {
  fast_io();
  solve();
  return 0;
}
