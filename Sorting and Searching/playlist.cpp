#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for(int i = 0, j = 0; i < n; i++) {
        if(pos.find(a[i]) == pos.end()) {
            pos[a[i]] = i;
        }
        else {
            if(pos[a[i]] >= j) {
                j = pos[a[i]] + 1;
                pos[a[i]] = i;
            }
            else pos[a[i]] = i;
        }
        res = max(res, i - j + 1);
    }
    
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}