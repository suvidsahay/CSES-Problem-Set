#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  double dp[k + 1], ans = 0; // dp[i] represents probability of maxElement = i
  memset(dp, 0, sizeof(dp));
  for (int j = 1; j <= k; j++) {
    dp[j] = 1.0;
    for (int i = 0; i < n; i++)
      dp[j] *= 1.0 * j / k;
    for (int i = 1; i <= j - 1; i++)
      dp[j] -= dp[i];
    ans += dp[j] * j;
  }
  cout << fixed << setprecision(6) << ans;

  return 0;
}