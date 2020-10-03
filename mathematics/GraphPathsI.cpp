#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

/**
 * Read about Matrix Exponentiation Here:
 * https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/
 **/

struct Matrix {
  vector<vector<ll>> mat;
  ll n_rows, n_cols;

  Matrix(vector<vector<ll>> values)
      : mat(values), n_rows(values.size()), n_cols(values[0].size()) {}

  static Matrix identity_matrix(ll n) {
    vector<vector<ll>> values(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
      values[i][i] = 1;
    return values;
  }

  Matrix operator*(const Matrix &other) const {
    ll n = n_rows, m = other.n_cols;
    vector<vector<ll>> result(n_rows, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++) {
        for (ll k = 0; k < n_cols; k++) {
          result[i][j] =
              (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % mod;
        }
      }
    return Matrix(result);
  }

  inline bool is_square() const { return n_rows == n_cols; }

  friend ostream &operator<<(ostream &os, const Matrix &M) {
    for (int i = 0; i < M.n_rows; ++i) {
      for (int j = 0; j < M.n_cols; ++j) {
        cout << M.mat[i][j] << " ";
      }
      cout << "\n";
    }
    return os;
  }
};

Matrix fast_exponentiation(Matrix m, ll power) {
  assert(m.is_square());
  Matrix result = Matrix::identity_matrix(m.n_rows);
  while (power) {
    if (power & 1)
      result = result * m;
    m = m * m;
    power >>= 1;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> adj(n, vector<ll>(n));
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    adj[x][y]++;
  }
  Matrix M(adj);
  M = fast_exponentiation(M, k);
  cout << M.mat[0][n - 1];

  return 0;
}