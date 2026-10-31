#include <iostream>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int a, b;
  cin >> a >> b;
  int countA = 0, countB = 0;

  for (int i = 0; i < a; i++) {
    int tmp;
    cin >> tmp;
    countA += tmp;
  }

  for (int i = 0; i < b; i++) {
    int tmp2;
    cin >> tmp2;
    countB += tmp2;
  }

  cout << countB - countA;
}

int main() {
  fast_io();
  solve();
  return 0;
}
