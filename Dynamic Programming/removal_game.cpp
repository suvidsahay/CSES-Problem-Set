#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[n][n] = {0};

    for(int i = 0; i < n; i++) {
        dp[i][i] = a[i];
        if(i + 1 < n) {
            dp[i][i + 1] = max(a[i], a[i + 1]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(i == j || i + 1 == j) continue;
            else {
                dp[i][j] = max(dp[i][i] + min(dp[i + 2][j], dp[i + 1][j - 1]), dp[j][j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}