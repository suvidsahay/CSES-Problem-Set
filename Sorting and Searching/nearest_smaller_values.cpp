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

    stack<array<int, 2>> pos;

    for(int i = 0; i < n; i++) {
        if(pos.empty()) {
            cout << 0 << " ";
            pos.push({a[i], i});
        }
        else {
            while(!pos.empty() && pos.top()[0] >= a[i]) {
                pos.pop();
            }

            if(pos.empty()) {
                cout << 0 << " ";
            }
            else cout << pos.top()[1] + 1 << " ";
            pos.push({a[i], i});
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}