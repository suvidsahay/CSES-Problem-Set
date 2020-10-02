#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    char a[n][n];
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(a[n - 1][i] == '*') {
            break;
        }    
        else dp[n - 1][i] = 1;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(a[i][n - 1] == '*') {
            break;
        }    
        else dp[i][n - 1] = 1;
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 2; j >= 0; j--) {
            if(a[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
        }
    }
    
    cout << dp[0][0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}