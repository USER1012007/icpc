#include <iostream>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solve() {
  string gen;
  cin >> gen;
  int num_genes;
  cin >> num_genes;
  int genes[num_genes];
  for (int i = 0; i < num_genes; i++) {
    cin >> genes[i];
  }
  int queries;
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    if (gen.find(genes[i]) != string::npos) {
      cout << i << "\n";
    } else {
      cout << "-1" << "\n";
    }
  }
}

int main() {
  fast_io();
  solve();
  return 0;
}
