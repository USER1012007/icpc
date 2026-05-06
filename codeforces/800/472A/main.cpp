#include <bits/stdc++.h>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  int x = 8;
  if (n & 1)
    x++;
  cout << x << " " << n - x;
}

int main() {
  fast_io();
  solve();
  return 0;
}
