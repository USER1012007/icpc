#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

typedef long long ll;

int main(){
  FAST_IO;
  
  ll t, MOD = 1e9 + 7;
  cin >> t;
  
  ll r;
  for (ll i = 0; i < t; i++) {
    ll n;
    cin >> n;
    if ((n & 1) == 0) {
      long long pares = n / 2;
      r = (pares * pares * (pares - 1)) / 2;
      r += pares * (pares - 1) * (pares - 2) / 6;
    } else {
      ll pares = (n - 1) / 2;
      ll impares = pares + 1;
      r = (pares * impares * (impares - 1)) / 2;
      r += pares * (pares - 1) * (pares - 2) / 6;
    }

    cout << r % MOD << "\n"; 
  }

  return 0;
}
