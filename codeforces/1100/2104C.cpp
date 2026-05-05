#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

bool solve() {
    int n;
    cin >> n;
    string s;

    cin >> s;

    if(n == 2) return (s[0] == 'B') ? true : false;
    if((s[n-1] == s[n-2]) || (s[0] == s[n-1])) return (s[n-1] == 'B') ? true : false;
    
    int count_b = 0;

    for(int c : s){
      if(c == 'B') count_b++;
      
    }

    if(count_b > 1 && (s[n-1] == 'B' || s[0] == 'B')) return true;

    return false; 
}

int main(){
  FAST_IO;
  int t;
  cin >> t;

  while(t--){
    cout << (solve() ? "Bob" : "Alice") << "\n";
  }

  return 0;
}

