#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007

using namespace std;
int n, q;

void solve() {
    
    int n, q;
    cin >> n >> q;
    char forest[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    int dp[n][n];
    if(forest[0][0] == '*') {
        dp[0][0] = 1;
    }
    else dp[0][0] = 0;
    for(int i = 1; i < n; i++) {
        if(forest[i][0] == '*') {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        else dp[i][0] = dp[i - 1][0];

        if(forest[0][i] == '*') {
            dp[0][i] = dp[0][i - 1] + 1;
        }
        else dp[0][i] = dp[0][i - 1];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if(forest[i][j] == '*') {
                dp[i][j]++;
            }
        }
    }

    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--, l2--, r1--, r2--;
        if(l1 == 0 && r1 == 0) {
            cout << dp[l2][r2] << endl;
        }
        else if(l1 == 0) {
            cout << dp[l2][r2] - dp[l2][r1 - 1] << endl;
        }
        else if(r1 == 0) {
            cout << dp[l2][r2] - dp[l1 - 1][r2] << endl;
        }
        else {
            cout << dp[l2][r2] - dp[l1 - 1][r2] - dp[l2][r1 - 1] + dp[l1 - 1][r1 - 1] << endl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}