#include <iostream>

using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  ll n, k;
  cin >> n >> k;
  if (n % 2 == k % 2 && n >= k * k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  fast_io();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
