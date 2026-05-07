#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  int n;
  cin >> n;

  if (n & 1) {
    n /= 2;
    n--;
    cout << n + 1 << '\n' << 3 << ' ';
  } else {
    n /= 2;
    cout << n << '\n';
  }

  for (int i = 0; i < n; i++)
    cout << 2 << ' ';
}

int main() {
  fast_io();
  solve();
  return 0;
}
