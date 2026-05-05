#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  int n_wal = 1;
  while (1) {
    if (m - n_wal < 0)
      break;

    m -= n_wal;

    if (n_wal == n)
      n_wal = 0;

    n_wal++;
  }
  cout << m;
  return 0;
}
