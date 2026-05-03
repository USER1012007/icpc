#include<bits/stdc++.h>
using namespace std;

bool is_possible(){
    long long n;
    cin >> n;
    long long array[n];
    for(long long j = 0; j < n; j++)cin >> array[j];

    long long sum_par = 0, cont_par = 0, sum_impar = 0, cont_impar = 0;
    for(long long j = 0; j < n; j++){
      if(j%2 == 0){
        sum_par+=array[j];
        cont_par++;
      }else{
        sum_impar+=array[j];
        cont_impar++;
      }
    }

    if(sum_par % cont_par != 0)return false;
    if(sum_impar % cont_impar != 0)return false;
    if(sum_par / cont_par != sum_impar / cont_impar)return false;
    return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string output = "";
  int n_queries;
  cin >> n_queries;

  for(int i = 0; i < n_queries; i++)output += is_possible() ? "YES\n" : "NO\n";

  cout << output;

  return 0;
}
