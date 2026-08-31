#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  int C[n], K[n];
  int result = 1e5;
  int index = 0;
  int sum = 0;

  for (int i = 0; i < n; i++)
    cin >> C[i];

  for (int i = 0; i < n; i++) {
    cin >> K[i];
    int diff = C[i] - K[i];
    if (diff < 0) {
      sum = -1;
    } else if (diff < result) {
      result = diff;
      index = i;
    }
  }

  if (sum != -1) {
    for (int i = 0; i < n; i++) {
      if (i != index) {
        sum += C[i];
      } else {
        sum += K[i];
      }
    }
  }

  cout << sum;
}

int main() {
  fast_io();
  solve();
  return 0;
}
