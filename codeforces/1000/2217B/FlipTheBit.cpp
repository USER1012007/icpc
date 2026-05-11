#include<bits/stdc++.h>
using namespace std;

int test_case(){
  int n, k, p, x;
  cin >> n >> k;

  bool bits[n];
  for(int i = 0; i < n; i++)cin >> bits[i];
  cin >> p;
  //x = bits[p-1];

  int cont_l = 0, cont_r = 0;

  for(int i = p; i < n; i++)
    if(bits[i-1] ^ bits[i]) cont_r++;

  for(int i = p-2; i >= 0; i--)
    if(bits[i+1] ^ bits[i]) cont_l++;
  
  int op = max(cont_l, cont_r);

  return (op & 1) ? (op+1) : (op) ;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    cout << test_case() << "\n";
  }

  return 0;
}
