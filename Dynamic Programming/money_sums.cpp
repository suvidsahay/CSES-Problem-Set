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
    int dp[100005] = {0};

    dp[0] = 1;
    for(int j = 0; j < n; j++) {
        for(int i = 100004; i >= 0; i--) {
            dp[i] = dp[i] | (i - a[j] >= 0 ? dp[i - a[j]] : 0);
        }
    }

    vector<int> res;
    for(int i = 1; i < 100005; i++) {
        if(dp[i] == 1) {
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}