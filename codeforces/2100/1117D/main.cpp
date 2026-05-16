#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
const int MOD = 1e9 + 7;

matrix multiply(const matrix& A, const matrix& B) {
    int r = A.size(), c = B[0].size(), m = A[0].size();
    matrix C(r, vector<ll>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int k = 0; k < m; ++k) {
            for (int j = 0; j < c; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

matrix matrixPower(matrix A, ll p) {
    int n = A.size();
    matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;

    while (p) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

int main(){
  FAST_IO;
  ll n, m;

  cin >> n >> m;

  matrix mat(m, vector<ll>(m, 0));

  for(int i=0; i<m-1; ++i){
    mat[i][i+1] = 1;
  }

  for(int i=0; i<m; ++i){

  }
  mat[m-1][m-1] = 1;
  mat[m-1][0] = 1;

  matrix result = matrixPower(mat, n);

  ll comb = 0;
  for(int i=0; i<m; ++i){
    comb = (comb + result[0][i]) % MOD;
  }

  cout << comb << "\n";
  return 0;
}
