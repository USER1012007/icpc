#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {

  int n, m;
  int sumn = 0, summ = 0;

  cin >> n >> m;

  int arrn[n], arrm[m];

  for (int i = 0; i < n; i++) {
    cin >> arrn[i];
    sumn += arrn[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> arrm[i];
    summ += arrm[i];
  }

  if ((sumn * 1.1) >= summ) {
    cout << "NO";
  } else {
    cout << "YES";
  }

  return 0;
}
