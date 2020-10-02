#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;
 
void solve() {
    int a, b;
    cin >> a >> b;
    int dp[a][b];

    for(int i = 0; i < min(a, b); i++) {
        dp[i][i] = 0;
    }
    for(int i = 1; i < a; i++) {
        dp[i][0] = 1 + dp[i - 1][0];
    }
    for(int i = 1; i < b; i++) {
        dp[0][i] = 1 + dp[0][i - 1];
    }

    for(int i = 1; i < a; i++) {
        for(int j = 1; j < b; j++) {
            if(i == j) continue;
            int res = 500;
            for(int k = i - 1; k >= 1; k--) {
                res = min(res, dp[k][j] + dp[i - k - 1][j]);
            }
            for(int k = j - 1; k >= 1; k--) {
                res = min(res, dp[i][k] + dp[i][j - k - 1]);
            }
            res++;
            dp[i][j] = res;
        }
    }

    cout << dp[a - 1][b - 1] << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}