#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  cout << arr[n - 1] - arr[0] << endl;
}

int main() {
  fast_io();
  solve();
  return 0;
}
