#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

  int n, q;

  cin >> n >> q;

  vector<int> arrq(q, 0);

  for (int i = 0; i < q; i++) {
    cin >> arrq[i];
  }
  int max = sqrt(*max_element(arrq.begin(), arrq.end())) + 2;
  int fact[q][max];

  for (int i = 0; i < q; i++) {
    for (int i = 0; i < max; i++) {
    }
  }
  return 0;
}
