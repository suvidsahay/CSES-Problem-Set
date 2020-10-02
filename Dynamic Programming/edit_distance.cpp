#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()) {
        swap(a, b);
    }

    int dp[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof(0));
    for(int i = b.size(); i >= 0; i--) {
        dp[a.size()][i] = b.size() - i;
    }
    for(int i = a.size(); i >= 0; i--) {
        dp[i][b.size()] = a.size() - i;
    }

    for(int i = a.size() - 1; i >= 0; i--) {
        for(int j = b.size() - 1; j >= 0; j--) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
            }
        }
    }

    // for(int i = 0; i <= a.size(); i++) {
    //     for(int j = 0; j <= b.size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    cout << dp[0][0] << endl;
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}