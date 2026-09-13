#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

// int max_subarray_sum(int arr[], int n, int start_index) {
//   int max_sum = arr[start_index];
//   int current_sum = arr[start_index];
//
//   for (int i = start_index + 1; i < n; i++) {
//     current_sum += arr[i];
//     if (current_sum > max_sum) {
//       max_sum = current_sum;
//     }
//   }
//
//   return max_sum;
// }

int max_subarray_sum(int arr[], int n, int start_index) {
  if (start_index >= n) {
    return 0;
  }

  int current_sum = arr[start_index];
  int max_sum = current_sum;

  int next_max_sum = max_subarray_sum(arr, n, start_index + 1);
  current_sum += next_max_sum;

  if (current_sum > max_sum) {
    max_sum = current_sum;
  }

  return max_sum;
}

void solve() {
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int query;

  for (int j = 0; j < q; j++) {
    cin >> query;
    int max_sum = arr[query + 1];
    int current_sum = arr[query + 1];

    if (query == n - 1) {
      cout << arr[n - 1] << '\n';
      continue;
    }

    cout << max_subarray_sum(arr, n, query + 1) << '\n';
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
