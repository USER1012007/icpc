#include <bits/stdc++.h>
using namespace std;

string verify(int pos, int numCaracteres, string s) {
  string res = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - '0' >= 1 && s[i] - '0' <= 9) {
      res += s[i];
    }
  }
  return res;
}

int main(int argc, char *argv[]) {

  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) {
    string linea;
    cin >> linea;

    int counter = 0;
    for (int j = 1; j <= s[i].size(); j++) {
      if (linea[j] - '0' >= 1 && linea[j] - '0' <= 9 && linea[j - 1] == ' ') {
        counter++;
      }
    }
    int positions[counter][2];
    string numbers[counter];

    int i_num = 0;
    for (int j = 1; j <= s[i].size(); j++) {
      if (linea[j] - '0' >= 1 && linea[j] - '0' <= 9) {
        numbers[i_num] += linea[j];
        if (!(linea[j - 1] - '0' >= 1 && linea[j - 1] - '0' <= 9)) {
          positions[i_num][0] = j;
        }
        if (!(linea[j + 1] - '0' >= 1 && linea[j + 1] - '0' <= 9)) {
          positions[i_num][1] = j;
          i_num++;
        }
      }
    }

    s[i] = linea;
  }

  return 0;
}
