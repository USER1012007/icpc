#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll test_case(){
  ll n, sum = 0;
  cin >> n;

  while(n!=0){
    sum += n;
    n /= 2;
  }

  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    cout << test_case() << "\n";
  }
  
  return 0;
}
