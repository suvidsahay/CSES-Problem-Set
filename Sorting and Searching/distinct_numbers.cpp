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
    sort(a, a + n);
    int res = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            continue;
        }
        else {
            res++;
        }
    }
    cout << res + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}