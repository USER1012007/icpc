#include <algorithm>
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
  ll arrm[m], arrn[n];
  ll difm[m + 1], difn[n];

  for (ll i = 0; i < m; i++) {
    cin >> arrm[i];
    difm[i] = arrm[i];
    if (i > 0)
      difm[i] -= arrm[i - 1];
  }

  for (ll i = 0; i < n; i++) {
    cin >> arrn[i];
    difn[i] = arrn[i];
    if (i > 0)
      difn[i] -= arrn[i - 1];
  }

  ll counter = n - m + 1;

  cout << "arrm: " << '\n';
  for (ll i : arrm) {
    cout << i << " ";
  }
  // cout << "difm: " << '\n';
  // for (ll i : difm) {
  //   cout << i << " ";
  // }
  // cout << '\n' << "difn: " << '\n';
  // for (ll i : difn) {
  //   cout << i << " ";
  // }

  ll tmp = 0;
  for (ll i = 0; i < n - m + 1; i++) {
    tmp = arrn[i] - arrm[i];
    cout << "tmp: " << tmp << endl;
    for (ll j = i; j < m + i; j++) {

      cout << arrn[j] << " - " << arrm[j] << " = " << arrn[j] - arrm[j] << endl;
      if (!(tmp == (arrn[j] - arrm[j]))) {
        counter--;
        break;
      }
    }
  }

  cout << counter;
}

int main() {
  fast_io();
  ll t;
  solve();
  return 0;
}
