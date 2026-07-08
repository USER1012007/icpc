#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n = 3;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cout << string(i, '*') << '\n';
  }
  return 0;
}
