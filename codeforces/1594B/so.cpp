#include <iostream>

using namespace std;

void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long MOD = 1e9 + 7;
  long long power_of_n = 1;

  while (k > 0) {
    if (k % 2 == 1) {
      ans = (ans + power_of_n) % MOD;
    }
    power_of_n = (power_of_n * n) % MOD;
    k /= 2;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
