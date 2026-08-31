#include <iostream>
#include <math.h>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  cout << round(n + (n * .7));
}

int main() {
  fast_io();
  solve();
  return 0;
}
