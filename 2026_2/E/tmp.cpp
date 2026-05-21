#include <iostream>
#include <regex>

using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fast_io();

  string s;
  cin >> s;
  regex re(R"(mesero)");

  string result = regex_replace(s, re, "taquero");
  cout << result;
  return 0;
}
