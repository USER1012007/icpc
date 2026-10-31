#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

vector<string> list;

int isValid(string token) {
  for (string tmp : list) {
    if (token == tmp) {
      return 1;
    }

    string deslizada = token;

    for (int i = 0; i < token.size(); i++) {
      int j = i;
      int k = 0;

      for (; j < token.size(); j++, k++) {
        deslizada[k] = token[j];
      }

      for (int h = 0; h < i; h++, k++) {
        deslizada[k] = token[h];
      }

      if (tmp == deslizada) {
        return 1;
      }
    }
  }
  return 0;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string token;
    cin >> token;

    if (!isValid(token)) {
      list.push_back(token);
    }
  }

  cout << list.size();
}

int main() {
  fast_io();
  solve();
  return 0;
}
