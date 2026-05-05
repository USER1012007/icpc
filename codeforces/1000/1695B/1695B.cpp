#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long min_val = 1e18;
    int min_idx = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_val) {
            min_val = a[i];
            min_idx = i;
        }
    }

    if (n % 2 != 0) return true; 
    
    return (min_idx % 2 != 0); 
}

int main(){
  FAST_IO;
  int t;
  cin >> t;

  while(t--){
    cout << (solve() ? "Mike" : "Joe") << "\n";
  }

  return 0;
}
