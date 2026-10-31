
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAXN = 10000005;

ll spf[MAXN];
vector<ll> primes;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void build_sieve() {
  vector<ll> e(MAXN, 0);

  for (ll i = 2; i < MAXN; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      primes.push_back(i);
      e[i] = 1;
    }

    for (ll p : primes) {
      if (p > spf[i] || (ll)i * p >= MAXN)
        break;
      spf[i * p] = p;
      if (i % p == 0) {
        e[i * p] = e[i] + 1;
        break;
      } else {
        e[i * p] = 1;
      }
    }
  }
}

auto solve(ll n1, int n2) {
  vector<ll> factorsn1;
  vector<ll> factorsn2;
  set<ll> colision;

  while (n1 > 1) {
    ll p = spf[n1];
    while (n1 % p == 0) {
      n1 /= p;
    }

    factorsn1.push_back(p);
    colision.insert(p);
  }

  while (n2 > 1) {
    ll p = spf[n2];
    while (n2 % p == 0) {
      n2 /= p;
    }

    factorsn2.push_back(p);
    colision.insert(p);
  }

  return colision.size();
}

int main(int argc, char *argv[]) {
  fast_io();
  ll n;
  cin >> n;

  build_sieve();
  for (ll i = 0; i < n; i++) {
    ll a, b;

    cin >> a >> b;

    cout << solve(a, b) << '\n';
  }

  return 0;
}
