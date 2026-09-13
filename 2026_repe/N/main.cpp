#include <iostream>
#include <math.h>

using namespace std;
typedef long double ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  ll l, r;
  cin >> l >> r;
  if (1 + (8 * l) < 0) {
    cout << 0;
    return;
  }
  ll sol1l = (-1 + sqrt(1 + (8 * l))) / 2;
  ll sol2l = (-1 - sqrt(1 + (8 * l))) / 2;
  ll solposl = max(sol1l, sol2l);
  if (solposl < 0) {
    cout << 0;
    return;
  }

  solposl = ceil(solposl);
  if ((1 + (8 * r) < 0) || l == r) {
    cout << 1;
    return;
  }

  ll sol1r = (-1 + sqrt(1 + (8 * r))) / 2;
  ll sol2r = (-1 - sqrt(1 + (8 * r))) / 2;
  ll solposr = max(sol1r, sol2r);
  if (solposr < 0) {
    cout << 1;
    return;
  }

  solposr = floor(solposr);
  cout << (long long)(solposr - solposl + 1);
}

int main() {
  fast_io();
  solve();
  return 0;
}
