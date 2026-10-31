#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fast_io();
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    int res = ((a + 1) * (a + 2) / 2) * (b + 1);
    cout << res % (int)1e7 << '\n';
  }
  return 0;
}
