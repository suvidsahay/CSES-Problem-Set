#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int x[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    int l = sum / k, h = sum;
    int m, ans = l;
    while(l <= h) {
        // cout << l << " " << h << endl;
        m = (l + h) / 2;
        int count = k, i = 0;
        while(count--) {
            int s = 0;
            while(i < n) {
                s += x[i];
                if(s > m) {
                    break;
                }
                i++;
            }
        }
        if(i != n) {
            l = m + 1;
        }
        else {
            ans = m;
            h = m - 1;
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