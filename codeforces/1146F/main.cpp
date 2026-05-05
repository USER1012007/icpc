#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  ll n;
  cin >> n;

  // vector<ll> tree;
  vector<bool> leaves(n, true);

  leaves[0] = false;

  int count = n;
  for (int i = 0; i < n - 1; i++) {
    ll conection;
    cin >> conection;
    leaves[conection] = false;
    n--;
  }
}

int main() {
  fast_io();
  int t = 1;
  solve();
  return 0;
}
