#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;

using namespace std;

ll solve(){
  ll r = 0ll, pot = 1; // Todas las n^0 = 1 (2 <= n <= 1e9)
  ll mod = 1e9 + 7;
  unsigned int n, k;
  
  cin >> n >> k;

  while(k > 0){
    if((ll) k & 1){
      r = ( r + pot) % mod;
    }

    pot = (pot * (ll) n) % mod;
    k = k >> 1;
  }

  return r;
}

int main(){
  FAST_IO;

  int t;
  ll n, k;

  cin >> t;

  while(t--){
    cout << solve() << "\n";
  }

  return 0;
}
