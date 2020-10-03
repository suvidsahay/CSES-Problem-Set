#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;
  double dp[8][8];  
  double ans[8][8];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      ans[i][j] = 1.0;
  for (int ii = 0; ii < 8; ii++) {
    for (int jj = 0; jj < 8; jj++) {
      memset(dp, 0, sizeof(dp));
      dp[ii][jj] = 1.0;
      int p = k;
      while (k--) {
        double dp1[8][8];
        for (int i = 0; i < 8; i++)
          for (int j = 0; j < 8; j++)
            dp1[i][j] = 0;
        for (int i = 0; i < 8; i++) {
          for (int j = 0; j < 8; j++) {
            int k = 4;
            if (i == 0 || i == 7)
              k--;
            if (j == 0 || j == 7)
              k--;
            double add = dp[i][j] / k;
            if (i != 0)
              dp1[i - 1][j] += add;
            if (i != 7)
              dp1[i + 1][j] += add;
            if (j != 0)
              dp1[i][j - 1] += add;
            if (j != 7)
              dp1[i][j + 1] += add;
          }
        }
        for (int i = 0; i < 8; i++)
          for (int j = 0; j < 8; j++)
            dp[i][j] = dp1[i][j];
      }
      k = p;
      for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
          ans[i][j] *= 1.0 - dp[i][j];
    } 
  }
  double exp = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      exp += ans[i][j];
  cout << fixed << setprecision(6) << exp;

  return 0;
}