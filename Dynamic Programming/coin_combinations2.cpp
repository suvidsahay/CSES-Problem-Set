#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[x + 1];
    for(int i = 0; i <= x; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i <= x; i++) {
            dp[i] = (dp[i] +  ((i - a[j] >= 0) ? dp[i - a[j]] : 0)) % MOD;
        }
    }

    cout << dp[x] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}