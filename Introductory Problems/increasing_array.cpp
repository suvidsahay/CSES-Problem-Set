#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0) {
            res += max((int)0, a[i - 1] - a[i]);
            a[i] = max(a[i - 1], a[i]);
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}