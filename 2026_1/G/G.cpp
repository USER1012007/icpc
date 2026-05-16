#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {

  int n;
  cin >> n;
  bool arrn[n];

  int count = 0;

  for (int i = 0; i < n; i++) {
    arrn[i] = false;
  }

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arrn[tmp - 1] = true;
  }

  for (int i = 0; i < n; i++) {
    if (arrn[i] == false) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
