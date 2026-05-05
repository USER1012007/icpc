#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a = 0, b;

  cin >> n >> m;
  int contador = 0;
  for (a = 0; a <= m; a++) {
    b = n - a * a;
    if (b * b == m - a && b >= 0) {

      contador++;
    }
  }
  cout << contador;

  return 0;
}
