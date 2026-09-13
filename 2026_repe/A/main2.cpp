#include <iostream> #include <vector>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  int n, q;

  cin >> n >> q;

  int arr[n], arrq[q];
  vector<int> arrsum(n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      arrsum[i + 1] = arr[i];
    } else {
      arrsum[i + 1] = arrsum[i] + arr[i];
    }
  }

  for (int i = 0; i < q; i++) {
    cin >> arrq[i];

    int query = arrq[i];
    int query_index = query + 1;
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
