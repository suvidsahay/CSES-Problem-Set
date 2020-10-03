#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  cin >> n >> a >> b;
  double dp[6 * n + 5]; /** dp[i] represents probability of
                            sum = i after every move **/
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  int k = n;
  while (k--) {
    double dp1[6 * n + 5];
    memset(dp1, 0, sizeof(dp1));
    for (int i = n - k - 1; i < 6 * n; i++)
      for (int j = i + 1; j < i + 7 && j <= 6 * n; j++)
        dp1[j] += dp[i] * 1.0 / 6.0;
    for (int i = 0; i <= 6 * n; i++)
      dp[i] = dp1[i];
  }
  double ans = 0;
  for (int i = a; i <= b; i++)
    ans += dp[i];
  cout << fixed << setprecision(6) << ans;

  return 0;
}