#include <iostream>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast_io();
  long long n;
  cin >> n;
  cout << (n >= 2 ? 25 : 5);
  return 0;
}
