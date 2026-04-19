#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  long long t;
  cin >> t;
  long long arrt[t];
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    if ((n & 1) == 0) {
      long long pares = n / 2;
      arrt[i] = (pares * pares * (pares - 1)) / 2;
      arrt[i] += pares * (pares - 1) * (pares - 2) / 6;
    } else {
      long long pares = (n - 1) / 2;
      long long impares = pares + 1;
      arrt[i] = (pares * impares * (impares - 1)) / 2;
      arrt[i] += pares * (pares - 1) * (pares - 2) / 6;
    }
  }

  for (long long i = 0; i < t; i++) {
    cout << arrt[i] % (long long)(10e9 + 7) << endl;
  }

  return 0;
}
