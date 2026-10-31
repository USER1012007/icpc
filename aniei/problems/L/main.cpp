#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

string solve(ll k) {
  if (k == 1)
    return "2";
  if (k & 1)
    return "(2*" + solve(k - 1) + ")";
  return "(" + solve(k / 2) + ")^2";
}

int main(int argc, char *argv[]) {
  fast_io();
  ll n;
  cin >> n;

  while (n--) {
    ll k;
    cin >> k;
    cout << solve(k) << '\n';
  }

  return 0;
}
