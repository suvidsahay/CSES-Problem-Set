#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

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

  ll n;
  cin >> n;
  vector<ll> ways(6);
  for (int i = 0; i < 6; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i + j > 6)
        break;
      if (i == 0)
        ways[j - 1]++;
      else
        ways[i + j - 1] += ways[i - 1];
    }
  }
  if (n <= 6) {
    cout << ways[n - 1];
    return 0;
  }
  vector<vector<ll>> v = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
  Matrix M(v);
  M = fast_exponentiation(M, n - 6);
  vector<vector<ll>> initial(6, vector<ll>(1));
  for (int i = 0; i < 6; i++)
    initial[i][0] = ways[6 - i - 1];
  M = M * Matrix(initial);
  cout << M.mat[0][0];

  return 0;
}