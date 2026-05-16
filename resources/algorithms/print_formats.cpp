#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// El problema exige archivos específicos en el juez (ej. "grafo.in" y "grafo.out")
void set_file_io(string filename) {
    // Redirige la entrada estándar (cin) al archivo .in
    freopen((filename + ".in").c_str(), "r", stdin);
    // Redirige la salida estándar (cout) al archivo .out
    freopen((filename + ".out").c_str(), "w", stdout);
}

// Redirección solo local (Para no estar pegando el caso de prueba en la terminal)
void set_local_io() {
    #ifndef ONLINE_JUDGE
    // Lee de un archivo local llamado input.txt y escribe en output.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

// Configuración de precisión para punto flotante (Double/Float)
void set_float_precision(int decimals = 9) {
    cout << fixed << setprecision(decimals);
}

// Impresión de Vectores / Arreglos de una dimensión
template<typename T>
void print_vector(const vector<T>& v, string sep = " ") {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i + 1 == v.size() ? "" : sep);
    }
    cout << "\n";
}

// Impresión de Matrices / Grillas 2D
template<typename T>
void print_matrix(const vector<vector<T>>& mat, string sep = " ") {
    for (const auto& row : mat) {
        print_vector(row, sep);
    }
}
// 5. Formato para problemas con múltiples casos de prueba estructurados
// Ejemplo: "Case #1: 42" (Muy común en problemas estilo Google/Regionales antiguos)
template<typename T>
void print_case(int case_num, T ans, bool space = true) {
    cout << "Case #" << case_num << ":" << (space ? " " : "") << ans << "\n";
}

int main() {
    // Optimización de I/O estándar
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // --- Ejemplos de uso rápido en competencia ---
    
    // Si te piden 6 decimales de precisión:
    set_float_precision(6); 
    cout << 3.1415926535 << "\n"; // Imprime: 3.141593
    
    vector<int> ans = {1, 2, 3, 4};
    print_vector(ans); // Imprime: "1 2 3 4" (sin espacio al final antes del \n)
    
    print_vector(ans, ","); // Imprime: "1,2,3,4"
    return 0;
}
