#include <iostream>
#include <vector>
#define FAST_IO cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n);

  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  
  int count = 1, dir = 0;

  for(int i=0; i<n-1; i++){
    if (a[i + 1] > a[i]) { 
      if (dir != 1) {
        count++;
        dir = 1;
      }
    } else if (a[i + 1] < a[i]) {
      if (dir != -1) {
        count++;
        dir = -1;
      }
    }
  }
  
  cout << count << '\n';
}

int main() {
  FAST_IO;

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
