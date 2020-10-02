#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);

    if((a + b) % 3 == 0 && (b <= 2 * a)) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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