// Colección de código útil para problemas que involucran ecuaciones modulares.
// Los algoritmos aquí trabajan con enteros no negativos.
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
// Regresa a % b (valor positivo)
int mod(int a, int b) {
    return ((a % b) + b) % b;
}
// Calcula gcd(a,b)
int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
// Calcula lcm(a,b)
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
// (a^b) mod m 
int powermod(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mod(ans * a, m);
        a = mod(a * a, m);
        b >>= 1;
    }
    return ans;
}
// Encuentra dos enteros x, y tal que ax+by=gcd(a,b).
// Si a y b son coprimos entonces x es el inverso de a (mod b)
// Retorna gcd(a, b)
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = extended_euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}
// Encuentra todas las soluciones para ax = b (mod n)
VI modular_linear_equation_solver(ll a, ll b, int n) {
    ll x, y;
    VI ret;
    int g = extended_euclid(a, n, x, y);
    if (!(b % g)) {
        x = mod(x * (b / g), n);
        for (int i = 0; i < g; i++)
            ret.push_back(mod(x + i * (n / g), n));
    }
    return ret;
}
// Encuentra b tal que ab = 1 (mod n), retorna -1 si falla
int mod_inverse(ll a, int n) {
    ll x, y;
    int g = extended_euclid(a, n, x, y);
    if (g > 1) return -1;
    return mod(x, n);
}
// Calcula los inversos modulares hasta n
vector<ll> precompute_inv_mod(int n, ll mod) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    return inv;
}
// Encuentra x, y tal que ax + by = c
// Retorna si el valor existe
bool linear_diophantine(ll a, ll b, ll c, ll &x, ll &y) {
    if (!a && !b) {
        if (c) return false;
        x = 0; y = 0;
        return true;
    }
    if (!a) {
        if (c % b) return false;
        x = 0; y = c / b;
        return true;
    }
    if (!b) {
        if (c % a) return false;
        x = c / a; y = 0;
        return true;
    }
    int g = gcd(a, b);
    if (c % g) return false;
    x = c / g * mod_inverse(a / g, b / g);
    y = (c - a * x) / b;
    return true;
}
int main() {
    ll x, y;
    int g = extended_euclid(14, 30, x, y);
    cout << g << " " << x << " " << y << endl; //2 -2 1
    VI sols = modular_linear_equation_solver(14, 30, 100);
    for (int i = 0; i < sols.size(); i++) cout << sols[i] << " "; // 95 451
    cout << endl;
    cout << mod_inverse(8, 9) << endl; // 8
    if (!linear_diophantine(7, 2, 5, x, y)) cout << "ERROR" << endl;
    cout << x << " " << y << endl; // 5 -15
    return 0;
}
