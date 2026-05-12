#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

string solve(){
  unsigned int n;
  cin >> n;

  if(!n) return "YES";

  while (!n && !(n & 1)) {
    n >>= 1;
  }

  unsigned int original = n;
  unsigned int reversed = 0;
  int length = 0;

  while(n){
    reversed <<= 1;
    reversed |= (n & 1);
    n >>= 1;
    length++;
  }
  
  if (original != reversed) return "NO";

  if (length & 1) {
    int middle_index = length / 2;
    if ((original >> middle_index) & 1) {
       return "NO";
    }
  }

  return "YES";
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
