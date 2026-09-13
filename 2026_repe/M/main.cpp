#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n;
  bool condition = true;

  cin >> n;

  vector<int> b(n);
  vector<bool> verify(n, false);

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (!verify[b[i]]) {
      verify[b[i]] = true;
    } else {
      condition = false;
      cout << "NO" << '\n';
    }
  }

  if (!condition) {
    return;
  }

  bool M[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        M[i][j] = false;
      } else {
        while (b[i] > 0) {
          M[i][j] = true;
          M[j][i] = false;

          cout << "b(i): " << b[i] << '\n';
          cout << "i: " << i << ", j:" << j << '\n';
          b[i]--;
          j++;
        }
      }
      if (j >= n) {
        break;
      }
    }
  }

  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i][j] << " ";
    }
    cout << '\n';
  }
}

int main() {
  fast_io();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
