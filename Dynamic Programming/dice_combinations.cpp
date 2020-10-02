#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = i; j >= max((int)1, i - 6); j--) {
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
        if(i <= 6) {
            dp[i] = (dp[i] + 1) % MOD;
        }
    }
    cout << dp[n] << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}