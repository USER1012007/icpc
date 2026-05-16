#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fast_io();

  int n, k;
  if (!(cin >> n >> k))
    return 0;

  k = min(k, n);

  vector<long long> a(2 * n);
  vector<int> type(2 * n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> type[i];
    type[i + n] = type[i];
  }

  vector<long long> pref_points(2 * n + 1, 0);
  vector<long long> pref_coins(2 * n + 1, 0);

  for (int i = 0; i < 2 * n; i++) {
    long long pt = (type[i] == 1) ? a[i] : -a[i];
    long long cn = (type[i] == 2) ? a[i] : 0;
    pref_points[i + 1] = pref_points[i] + pt;
    pref_coins[i + 1] = pref_coins[i] + cn;
  }

  auto get_points = [&](int i, int j) {
    return pref_points[j + 1] - pref_points[i];
  };

  auto get_coins = [&](int i, int j) {
    return pref_coins[j + 1] - pref_coins[i];
  };

  vector<vector<bool>> dp(k + 1, vector<bool>(2 * n, false));
  long long max_coins = 0;

  for (int i = 0; i < 2 * n; i++) {
    if (type[i] == 1) {
      dp[1][i] = true;
      if (i < n) {
        max_coins = max(max_coins, get_coins(i, i));
      }
    }
  }

  for (int len = 2; len <= k; len++) {
    for (int i = 0; i <= 2 * n - len; i++) {
      int j = i + len - 1;

      if (dp[len - 1][i + 1]) {
        long long pts_before = get_points(i + 1, j);
        long long req = (type[i] == 2) ? a[i] : 0;
        if (pts_before >= req) {
          dp[len][i] = true;
        }
      }

      if (!dp[len][i] && dp[len - 1][i]) {
        long long pts_before = get_points(i, j - 1);
        long long req = (type[j] == 2) ? a[j] : 0;
        if (pts_before >= req) {
          dp[len][i] = true;
        }
      }

      if (dp[len][i] && i < n) {
        max_coins = max(max_coins, get_coins(i, j));
      }
    }
  }

  cout << max_coins << "\n";

  return 0;
}
