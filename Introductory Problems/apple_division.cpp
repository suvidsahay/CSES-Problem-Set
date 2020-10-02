#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int res = 0;

    for(int i = 0; i < 1 << n; i++) {
        
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                count += a[j];
            }
        }
        if(count <= sum / 2) {
            res = max(res, count);
        }
    }
    cout << sum - 2 * res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}