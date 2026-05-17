#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

bool solve() {
  ll x1, y1, r1;
  ll x2, y2, r2;
  ll k;

  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  cin >> k;

  ll difx = x2 - x1;
  ll dify = y2 - y1;
  double distancia = sqrt((difx * difx) + (dify * dify));
  ll sumr = r1 + r2;

  ll rmax = max(r1, r2);
  ll rmin = min(r1, r2);

  if (distancia > sumr)
    return false;

  double result = distancia + sumr;

  if (distancia == 0 || rmax >= (2 * rmin)) {
    return (2 * rmax) >= k;
  }

  return result >= k;
}

int main() {
  fast_io();
  int t;
  cin >> t;
  while (t--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
