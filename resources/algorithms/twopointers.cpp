#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;

  // 1. Ventana variable: mayor largo con suma <= k (a[i] >= 0)
  ll sum = 0;
  int best = 0;
  ll cnt = 0;
  int l = 0;
  for (int r = 0; r < n; r++) {
    sum += a[r];      // meter r
    while (sum > k) { // ventana inválida -> achicar
      sum -= a[l];
      l++;
    }
    best = max(best, r - l + 1); // ventana válida [l, r]
    cnt += r - l + 1; // cantidad de subarreglos válidos que terminan en r
  }

  // 2. Ventana fija de tamaño w: suma máxima
  int w = 3;
  ll s = 0, mx = LLONG_MIN;
  for (int r = 0; r < n; r++) {
    s += a[r];
    if (r >= w)
      s -= a[r - w]; // sacar el que sale
    if (r >= w - 1)
      mx = max(mx, s);
  }

  // 3. Dos punteros en arreglo ordenado: par con suma == k
  sort(a.begin(), a.end());
  int i = 0, j = n - 1;
  while (i < j) {
    ll t = a[i] + a[j];
    if (t == k) { /* encontrado */
      break;
    } else if (t < k)
      i++;
    else
      j--;
  }
}
