#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

  int n;
  int sum = 0;
  cin >> n;

  int a[n];
  int b[n];

  string s;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> s;

  b[0] = 1;

  for (int i = 1; i < n; i++) {
    char c = s[i - 1];
    switch (c) {
    case '<':
      b[i] = b[i - 1] + 1;
      break;
    case '>':
      if (b[i - 1] - 1 == 0) {
        for (int j = i; j > 0; j--) {
          b[j]++;
        }
      }
      b[i] = b[i - 1] - 1;
      break;
    case '=':
      b[i] = b[i - 1];
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    sum += b[i] * a[i];
  }

  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }

  return 0;
}
