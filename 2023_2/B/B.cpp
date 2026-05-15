#include <algorithm>
#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 7;

ll fact[MAX], inv[MAX], repe[MAX];

ll power(ll x, ll n){
  ll ans = 1;

  while(n){
    if(n & 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }

  return ans % MOD;
}

void precalc(){
  fact[0] = 1;
  for(ll i = 1; i < MAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
  inv[MAX-1] = power(fact[MAX-1], MOD-2);
  for(ll i = MAX - 2; i >= 0; --i) inv[i] = (inv[i+1] * (i + 1)) % MOD;
}

int main(){
  FAST_IO;
  int n, k;

  precalc();

  cin >> n >> k;

  vector<int> arrn(n);
  vector<pair<int, int>> queries(k);
  vector<int> values;
  ll fav = 1;

  for(int i = 0; i < n; i++){
    cin >> arrn[i];
    
    values.push_back(arrn[i]);
  }

  for(int i = 0; i < k; ++i){
    cin >> queries[i].first >> queries[i].second;

    values.push_back(queries[i].second);
  }

  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());

  auto get_id = [&](int x){
    auto it = lower_bound(values.begin(), values.end(), x);

    return (int) (it - values.begin());
  };
  
  for(int i = 0; i < n; i++){
    int id = get_id(arrn[i]);
    repe[id]++;
  }

  for(int i = 0; i < values.size(); i++) {
    if(repe[i] > 1) {
      fav = (fav * fact[repe[i]]) % MOD;
    }
  }

  cout << (fav * inv[n] % MOD) << "\n";

  int ant;
  for(auto& q : queries){
    int index = q.first - 1;
    int new_val = q.second;

    if(arrn[index] != new_val){
      ant = arrn[index];
      arrn[index] = new_val;

      fav = (fav * inv[ repe[get_id(ant)] ]) % MOD;
      repe[ get_id(ant) ]--;
      fav = (fav * fact[ repe[get_id(ant)] ]) % MOD;

      fav = (fav * inv[ repe[get_id(new_val)] ]) % MOD;
      repe[ get_id(new_val) ]++;
      fav = (fav * fact[ repe[get_id(new_val)] ]) % MOD;
    }

    cout << (fav * inv[n] % MOD) << "\n";
  }
  return 0;
}
