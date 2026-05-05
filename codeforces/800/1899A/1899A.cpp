#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool solve(){
  int n;
  cin >> n;

  if(n % 3 == 0) return false;
  return true;
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
