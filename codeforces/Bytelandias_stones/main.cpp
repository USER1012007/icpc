#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
  FAST_IO;
  int n;
  long long a, s = 0;
  cin >> n;

  for(int i=1; i<=n; ++i){
    cin >> a;
    s += a * (long long) i * (n - i + 1);
  }

  cout << s << endl;
  return 0;
}
