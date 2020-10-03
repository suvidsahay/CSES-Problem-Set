#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  bool dp[n + 1];
  memset(dp, false, sizeof(dp)); // dp[i] = false if 'i' is a losing position
  int a[n];
  for (int i = 0; i < k; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    if (!dp[i])
      for (int j = 0; j < k; j++)
        if (i + a[j] <= n)
          dp[i + a[j]] = true;
  for (int i = 1; i <= n; i++)
    cout << (dp[i] ? 'W' : 'L');

  return 0;
}