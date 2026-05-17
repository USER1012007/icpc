#include <cstring>
#include <iostream>
#include <string>

using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fast_io();
  string s;
  cin >> s;

  string patron = "mesero";
  string reemplazo = "taquero";

  for (size_t i = 0; i < s.size(); i++) {
    if (s.substr(i, patron.size()) == patron) {
      s.replace(i, patron.size(), reemplazo);
    }
  }
  cout << s;
}
