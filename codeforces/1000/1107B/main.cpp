#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
  FAST_IO;
  int n;
  long long k, x;

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> k >> x;    
    cout << x + 9 * (k - 1) << "\n";
  }

  return 0;
}
