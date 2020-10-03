#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int r[n];
  for (int i = 0; i < n; i++)
    cin >> r[i];
  double exp = 0;
  double dp[101]; /**  dp[i] represents expected number of elements greater than
                   or equal to i **/
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    double dp1[101];
    memset(dp1, 0, sizeof(dp1));
    for (int j = 1; j <= r[i]; j++) {
      exp += dp[j + 1] / r[i];
      dp1[j] += 1.0 / r[i];
    }
    for (int j = 100; j >= 1; j--)
      dp1[j - 1] += dp1[j], dp1[j] += dp[j];
    for (int j = 0; j <= 100; j++)
      dp[j] = dp1[j];
  }
  cout << fixed << setprecision(6) << exp;

  return 0;
}