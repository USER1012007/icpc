#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

vector<string> list;

void solve() {
  string palabra;
  int size;
  ll counter = 0;
  string final = "";

  cin >> palabra >> size;

  for (int i = 0; i < palabra.size(); i++) {

    if (isdigit(palabra[i])) {
      string tempo = "";

      if (palabra[i] == '0')
        continue;

      while (isdigit(palabra[i])) {
        tempo += palabra[i];
        i++;
      }
      if (tempo.length() > 7) {
        cout << "unfeasible\n";
        return;
      }

      ll tmp = stoll(tempo);

      if (tmp > 1e6) {
        cout << "unfeasible\n";
        return;
      }
      counter += tmp;

      final += string(tmp, palabra[i]);

    } else {
      counter++;
      final += palabra[i];
    }

    if (counter > size) {
      cout << "unfeasible\n";
      return;
    }
  }

  cout << final << '\n';
}

int main() {
  fast_io();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
