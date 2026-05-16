#include <iostream>
#include <string>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

typedef long long ll;

int main(){
  FAST_IO;

  int n;
  ll sum = 0;
  cin >> n;

  vector<int> a(n), b(n, 1);
  string s;

  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s;

  for(int i=1; i<n; ++i){
    if(s[i-1] == '=') b[i] = b[i-1];
    else if(s[i-1] == '<') b[i] = b[i-1] + 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '=') b[i] = b[i+1];
    else if (s[i] == '>') b[i] = max(b[i], b[i+1] + 1);
  }


  for (int i = 0; i < n; i++) {
    sum += (ll) b[i] * (ll) a[i];
  }

  cout << sum << "\n";
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }

  return 0;
}
