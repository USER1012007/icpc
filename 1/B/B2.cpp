#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      string num = "";
      if (c - '0' >= 1) {
        num += c;

        int count = 1;
        while (c != ' ') {
          c = s[i];
          cout << "c: " << c << endl;
          if (c - '0' >= 1) {
            num += c;
          } else if (c - '0' == 0) {
            count++;
          }
          cout << "oirefj" << endl;
          i++;
        }
        num += "{" + to_string(count) + "}";
      }
      res += num;
    }
    cout << res << endl;
  }
  return 0;
}
