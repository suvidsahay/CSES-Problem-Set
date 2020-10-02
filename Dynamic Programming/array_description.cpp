#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

int dp[100005][105];
int a[1000005];
int n, m;

int solve(int idx, int prev = 0) {
    int ans = 0;
    if(idx == n) {
        return 1;
    }

    if(dp[idx][prev] != -1) {
        return dp[idx][prev];
    }

    if(a[idx] == 0) {
        if(prev == 0) {
            for(int i = 1; i <= m; i++) {
                ans = (ans + solve(idx + 1, i)) % MOD;
            }
        }
        else {
            for(int i = max((int)1, prev - 1); i <= min(prev + 1, m); i++) {
                ans = (ans + solve(idx + 1, i)) % MOD;
            }
        }
    }
    else {
        if(prev == 0) {
            ans = solve(idx + 1, a[idx]);
        }   
        else {
            if(abs(a[idx] - prev) <= 1) {
                ans = solve(idx + 1, a[idx]);
            }
            else {
                ans = 0;
            }
        }
        
    }

    dp[idx][prev] = ans;
    return ans;
}

void solve() {

    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}