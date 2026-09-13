#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<bool> arr(n, false);

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp < n) {
      arr[tmp] = true;
    }
  }

  int i = 0;

  int maximum = 0;

  do {

    if (!arr[i] && k == 0) {
      break;
    }

    if (!arr[i]) {
      k--;
    }

    maximum++;
    i++;

    if (i > n - 1) {
      break;
    }

    if (!arr[i] && k > 0) {
      k--;
      arr[i] = true;
    }

    if (k == -1) {
      break;
    }

  } while (arr[i]);

  cout << maximum;
}

int main() {
  fast_io();
  solve();
  return 0;
}
