#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = INT_MIN, max_val = 0;
    for(int i = 0; i < n; i++) {
        max_val = max(max_val + a[i], a[i]);
        res = max(res, max_val);
    }

    cout << res << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}