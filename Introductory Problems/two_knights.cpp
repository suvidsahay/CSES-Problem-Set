#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n;i ++) {
        if( i <= 1) {
            cout << 0 << endl;
        }
        else {
            int ways = i * i;
            ways = (ways * (ways - 1)) / 2;
            ways -= 4 * (i - 1) * (i - 2);
            cout << ways << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}