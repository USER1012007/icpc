#include <iostream>
#include <math.h>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() {
  fast_io();
  string s;
  cin >> s;
  string palabra = "mesero";
  string reemplazo = "taquero";
  int palabra_size = palabra.size();
  int s_size = s.size();
  string sub = "";
  vector<ll> hashpalabra(s_size);
  vector<ll> hashmesero(palabra_size);

  ll p = 31;
  ll m = 1e9 + 9;
  for (ll i = 0; i < s_size; i++) {
    hashpalabra[i] = (s[i] - 'a' + 1) * (ll)pow(p, i) % m;
    if (i > 0) {
      hashpalabra[i] = (hashpalabra[i] + hashpalabra[i - 1]) % m;
    }
  }

  for (ll i = 0; i < palabra_size; i++) {
    hashmesero[i] = (palabra[i] - 'a' + 1) * (ll)pow(p, i) % m;
    if (i > 0) {
      hashmesero[i] = (hashmesero[i] + hashmesero[i - 1]) % m;
    }
  }

  ll i = 0;
  if (hashpalabra[0 + palabra_size - 1] == hashmesero[palabra_size - 1]) {
    sub += reemplazo;
    i += palabra_size;
  } else {
    sub += s[0];
  }

  for (ll j = i; j < s_size; j++) {
    if (j + 6 < s_size && hashpalabra[j + 6] - hashpalabra[j - 1] ==
                              hashmesero[5] * (ll)pow(p, j) % m) {

      sub += reemplazo;
      j += 6;

    } else {
      sub += s[j];
    }
  }

  cout << sub;
  return 0;
}
