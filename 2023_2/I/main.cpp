#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << ((n / k) >= m ? "Iron fist Ketil" : "King Canute");
}

int main() {
  fast_io();
  solve();
  return 0;
}
