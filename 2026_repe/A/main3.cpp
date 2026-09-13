#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int query;

  int max_xor = 0;
  for (int j = 0; j < q; j++) {
    cin >> query;

    int max_sum = arr[query];
    int current_sum = arr[query];

    for (int i = query; i < n; i++) {
      current_sum += arr[i];
      if (current_sum > max_sum) {
        max_sum = current_sum;
      }
    }

    cout << max_sum << '\n';
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
