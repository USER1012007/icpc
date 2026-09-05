#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;

  int sum = 0;
  vector<int> reduce;

  for (int i = 0; i < s.size(); i++) {
    int d = s[i] - '0';
    sum += d;

    if (i == 0)
      reduce.push_back(d - 1);
    else
      reduce.push_back(d);
  }

  if (sum <= 9) {
    cout << 0 << '\n';
    return;
  }

  int need = sum - 9;
  sort(reduce.begin(), reduce.end(), greater<int>());

  int ans = 0;
  for (int r : reduce) {
    need -= r;
    ans++;
    if (need <= 0)
      break;
  }

  cout << ans << '\n';
}

int main(int argc, char *argv[]) {

  ll t;
  cin >> t;
  while (t--) {

    solve();
  }
  return 0;
}
