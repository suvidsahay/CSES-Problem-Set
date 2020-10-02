#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int y, x;
    cin >> y >> x;
    if(y > x) {
        if(y % 2 == 0) {
            cout << y * y - x + 1 << endl;
        }
        else cout << (y - 1) * (y - 1) + x << endl;
    }
    else {
        if(x % 2 == 0) {
            cout << (x - 1) * (x - 1) + y << endl;
        }
        else cout << x * x - y + 1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}