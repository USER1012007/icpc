#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int ca = count(s.begin(), s.end(), 'a');
  if (ca <= n / 2) {
    cout << n + ca - (n - ca) - 1;
  } else {
    cout << n;
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
