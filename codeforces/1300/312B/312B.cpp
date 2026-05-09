#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
  FAST_IO;
  double a, b, c, d;

  cin >> a >> b >> c >> d;

  cout << (a/b) / (1.0 - (1.0 - a/b) * (1.0 - c/d)) << endl;
  return 0;
}
