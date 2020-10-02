#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> vec(n);
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }

    sort(vec.begin(), vec.end(), [](array<int, 3>& a, array<int, 3>& b) {
        return a[1] < b[1];
    });

    m[0] = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        auto itr = m.lower_bound(vec[i][0]);
        itr--;
        res = max(res, itr->second + vec[i][2]);
        m[vec[i][1]] =  res;
    }

    cout << res << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}