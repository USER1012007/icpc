#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    vector<bool> visited(n + 1, false);
    int curr = i;
    while (!visited[curr]) {
      visited[curr] = true;
      curr = arr[curr];
    }
    cout << curr << " ";
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
