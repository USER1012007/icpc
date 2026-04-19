#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

  long long n;
  long long sum = 0;
  cin >> n;

  long long a[n];
  long long b[n];

  string s;

  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> s;

  b[0] = 1;

  for (long long i = 1; i < n; i++) {
    char c = s[i - 1];
    switch (c) {
    case '<':
      b[i] = b[i - 1] + 1;
      break;
    case '>':
      cout << "i: " << i << endl;
      if (b[i - 1] - 1 == 0) {
        cout << "i: " << i << endl;
        cout << "b [i- 1]: " << b[i - 1] << endl;
        b[i - 1]++;
        for (long long j = i; j > 0; j--) {
          cout << "j: " << j << endl;
          switch (s[j]) {
          case '<':
            if (b[j] > b[j - 1] - 1) {
              b[j - 1] = b[j] - 1;
            }
            break;
          case '>':
            if (b[j] < b[j - 1] + 1) {
              b[j - 1] = b[j] + 1;
            }
            break;
          case '=':
            if (b[j] == b[j - 1]) {
              b[j - 1] = b[j];
            }
            break;
          default:
            break;
          }
        }
      } else {
        b[i] = b[i - 1] - 1;
      }
      break;
    case '=':
      b[i] = b[i - 1];
      break;
    default:
      return 0;
      break;
    }
  }

  for (long long i = 0; i < n; i++) {
    sum += b[i] * a[i];
  }

  cout << sum << endl;
  for (long long i = 0; i < n; i++) {
    cout << b[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}
