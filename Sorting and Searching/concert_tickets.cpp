#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, m, t;
    cin >> n >> m;
    set<pair<int, int>> ticket;
    for(int i = 0; i < n; i++) {
        cin >> t;
        ticket.insert({t, i});
    }
    for(int i = 0;i < m; i++) {
        cin >> t;
        auto itr = ticket.lower_bound({t + 1, 0});
        if(itr == ticket.begin()) {
            cout << -1 << endl;
        }
        else {
            itr--;
            cout << itr->first << endl;
            ticket.erase(itr);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}