#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Optimizamos Entrada/Salida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (!(cin >> t))
    return 0;

  vector<long long> trib(41);
  trib[0] = 0;
  trib[1] = 0;
  trib[2] = 1;
  for (int i = 3; i <= 40; i++) {
    trib[i] = trib[i - 1] + trib[i - 2] + trib[i - 3];
  }

  while (t--) {
    int n;
    cin >> n;
    // ¡PERFECTO! Acumula las respuestas en memoria y las imprime en bloques
    // grandes
    cout << trib[n] << "\n";
  }
  return 0;
}
