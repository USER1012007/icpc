#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
typedef long long ll;

int main(){
  FAST_IO;
  ll n;
  cin >> n;

  vector<ll> x(n);
  for(ll i = 0; i<n; ++i){
    cin >> x[i];
  }

  sort(x.begin(), x.end());
  
  ll min = 1e15, min_index;

  for(int i=0; i<n/2; ++i){
    if(x[i+n/2] - x[i] < min){
      min = x[i+n/2] - x[i];
      min_index = i;
    }
  }

  cout << x[min_index+n/2] - x[min_index] << endl;
  return 0;
}
