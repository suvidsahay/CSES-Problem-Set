#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> custom;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        custom.push_back({a, 1});
        custom.push_back({b, -1});
    }
    sort(custom.begin(), custom.end());

    int res = 0, count = 0;
    for(int i = 0; i < custom.size(); i++) {
        count += custom[i].second;
        res = max(res, count);
    }

    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}