#include <bits/stdc++.h>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, q;
  cin >> n >> q;
  int arr[n];

  vector<pair<int, int>> sum;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      sum[i].first = arr[i];
    } else {
      sum[i].first = sum[i - 1].first + arr[i];
    }
    sum[i].second = i;
  }

  sort(sum.begin(), sum.end());

  auto buscar_max = [&](vector<pair<int, int>> &sum, int index) {
    int max_sum = sum[index].first;
    for (int i = index + 1; i < n; i++) {
      if (sum[i].second > sum[index].second) {
        max_sum = max(max_sum, sum[i].first - sum[index].first);
      }
    }
    return max_sum;
  };

  vector<int> max_sums(n);
  for (int i = 0; i < n; i++) {
    int max = buscar_max(sum, i);
    max_sums[i] = max;
  }

  int query;

  for (int j = 0; j < q; j++) {
    cin >> query;
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
