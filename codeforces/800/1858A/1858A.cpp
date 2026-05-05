#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

bool solve(){
  unsigned int a, b, c;

  cin >> a >> b >> c;

  if(c & 1 ){ 
    if(a>=b)
      return true;
    else
     return false;
  }
  
  return ((!(c&1) && b>=a) ? false : true); 
}

int main(){
  FAST_IO;
  int t;
  cin >> t;

  while(t--){
    cout << (solve() ? "First" : "Second") << "\n";
  }

  return 0;
}
