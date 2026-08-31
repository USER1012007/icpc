#include <iostream>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a * c > b) {
    cout << b;
  } else {
    cout << a * c;
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
