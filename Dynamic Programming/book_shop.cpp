#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int price[n];
    int pages[n];
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    int dp[x + 1] = {0};

    // for(int i = 0; i < n; i++) {
    //     for(int j = x; j >= 0; j--) {
    //         dp[j] = max(j - books[i].first >= 0 ? dp[j - books[i].first] + books[i].second : 0, dp[j]);
    //     }
    // }

    for(int i = 0; i < n; i++) {
        for(int j = x; j >= 0; j--) {
            dp[j] = max(j - price[i] >= 0 ? pages[i] + dp[j - price[i]] : 0, dp[j]);
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