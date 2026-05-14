#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
  FAST_IO;
  int b, k;

  cin >> b >> k;

  int a, s = 0;
  for(int i=0; i<k; i++){
    cin >> a;

    s += (a & 1);
    s &= 1;
  }

  if( !(b & 1) ){
    cout << (!(a & 1) ? "even" : "odd");
    return 0;
  }

  cout << (s ? "odd" : "even");
  return 0;
}
