#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll combinations(int range, int k){
  ll combs = 0;

  if(range < k)return 0;

  ll n = range - k + 1;
  combs = (n*(n+1))/2;

  return combs;
}

ll test_case(){

  int n, k, q;
  cin >> n >> k >> q;
  bool a[n];

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    a[i] = (temp <= q) ? true : false;
  }

  ll combs = 0;
  int cont = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == true){
      cont++;
      if(i == n-1 || a[i+1] == false){
        combs += combinations(cont, k);
        cont = 0;
      }
    }
  }

  return combs;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    cout << test_case() << "\n"; 
  }

  return 0;
}
