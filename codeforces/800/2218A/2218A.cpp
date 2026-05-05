#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int solve(){
  int x;

  cin >> x;  
  
  return (x==67) ? x : x+1; 
}

int main(){
  FAST_IO;
  int t;
  cin >> t;

  while(t--){
    cout << solve() << "\n";
  }

  return 0;
}
