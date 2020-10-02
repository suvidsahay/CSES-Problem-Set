#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, t;
    cin >> n;
    vector<array<int, 2>> vec;
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        vec.push_back({x, y});
    }
    
    sort(vec.begin(), vec.end());
    int res = 0, time = 0;
    for(int i = 0; i < n; i++) {
        time += vec[i][0];
        res += vec[i][1] - time;
    }
    cout << res << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}