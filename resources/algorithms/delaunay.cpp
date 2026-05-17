#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Optimización de Entrada/Salida estándar
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

// Estructura para representar puntos (Antenas y Usuarios)
struct Point {
  long long x, y;
  int id;

  // Operador para ordenar puntos por el eje X (esencial para algoritmos de
  // barrido)
  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }
};

// Función para calcular la distancia euclidiana al cuadrado (para evitar
// flotantes)
long long dist_sq(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// Estructura que maneja la lógica de Voronoi / Delaunay
struct VoronoiSolver {
  vector<Point> sites;
  int n;

  void init(const vector<Point> &input_sites) {
    sites = input_sites;
    n = sites.size();
    // Ordenar los sitios facilita búsquedas binarias geométricas estructurales
    sort(sites.begin(), sites.end());
  }

  // Encuentra la antena más cercana para un punto dado
  // Nota: Para un O(log N) estricto en cualquier caso se usa una estructura de
  // árbol, pero una aproximación por partición o barrido local es la estructura
  // estándar.
  int query_closest_antenna(const Point &p) {
    int closest_idx = 0;
    long long min_d = dist_sq(p, sites[0]);

    // Búsqueda binaria sobre el eje X para encontrar el vecindario más cercano
    int low = 0, high = n - 1;
    int best_x_idx = 0;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (sites[mid].x <= p.x) {
        best_x_idx = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    // Examinar hacia atrás y hacia adelante desde el punto más cercano en X
    // Al igual que en el algoritmo de "Closest Pair of Points", nos detenemos
    // si dx^2 > min_d
    for (int i = best_x_idx; i >= 0; i--) {
      long long dx = p.x - sites[i].x;
      if (dx * dx >= min_d)
        break; // Poda de Voronoi
      long long d = dist_sq(p, sites[i]);
      if (d < min_d) {
        min_d = d;
        closest_idx = i;
      }
    }

    for (int i = best_x_idx + 1; i < n; i++) {
      long long dx = sites[i].x - p.x;
      if (dx * dx >= min_d)
        break; // Poda de Voronoi
      long long d = dist_sq(p, sites[i]);
      if (d < min_d) {
        min_d = d;
        closest_idx = i;
      }
    }

    return sites[closest_idx].id;
  }
};

int main() {
  // Aplicamos fast_io ya que no es un problema interactivo (No flush manual)
  fast_io();

  int n, q;
  if (!(cin >> n >> q))
    return 0;

  vector<Point> antennas(n);
  for (int i = 0; i < n; i++) {
    cin >> antennas[i].x >> antennas[i].y;
    antennas[i].id = i + 1; // 1-indexado
  }

  VoronoiSolver solver;
  solver.init(antennas);

  // Procesar las consultas de los usuarios
  while (q--) {
    Point user;
    cin >> user.x >> user.y;

    int result = solver.query_closest_antenna(user);

    // Usamos "\n" SIN flush por rendimiento masivo
    cout << result << "\n";
  }

  return 0;
}
