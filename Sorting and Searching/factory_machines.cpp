#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l = 0, h = INT64_MAX;
    int ans = h;
    while(l <= h) {
        int m = (l + h) / 2;
        int products = 0;
        for(int i = 0; i < n; i++) {
            products += min(m / a[i], (int)INT_MAX);
        }

        if(products >= t) {
            ans = m;
            h = m - 1;
        }
        else if(products < t) {
            l = m + 1;
        }
    }
    
    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}