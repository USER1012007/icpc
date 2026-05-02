#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  long long n, k;
  cin >> n >> k;
  long long modulo = 1e9 + 7;

  vector<long long> powers;
  int counter = 0;

  while (k > 0) {
    counter = 0;
    while (1) {
      if ((int)pow(2.0, (double)counter) >= k)
        break;

      counter++;
    }
    if ((int)pow(2.0, (double)counter) > k)
      counter -= 1;
    k -= (int)pow(2.0, (double)counter);
    powers.push_back(counter);

    cout << k << endl;
  }

  long long result = 0ll;
  for (long long e : powers)
    result += (long long)pow((double)n, (double)e) % modulo;

  cout << result % modulo;

  return 0;
}
