#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

typedef long long ll;

ll solve(){
  ll n;
  cin >> n;

  vector<int> a(n);

  for(int i=0; i<n; ++i){
    cin >> a[i];
  }

  int max_xor = 0;
  for(int i=0; i<n; ++i)
    for(int j=i; j<n; j++)
      max_xor = max(max_xor, a[i] ^ a[j]);

  return max_xor;
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
