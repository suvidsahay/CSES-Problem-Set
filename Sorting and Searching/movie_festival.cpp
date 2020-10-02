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
        custom.push_back({a, b});
    }
    sort(custom.begin(), custom.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});

    int start = custom[0].first, end = custom[0].second;
    int res = 1;
    for(int i = 1; i < custom.size(); i++) {
        if(custom[i].first >= end) {
            res++;
            end = custom[i].second;
        }
    }

    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}