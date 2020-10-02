#include<bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> p;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<p> adj[n+1];
    ll x, y, z;
    for(int i=0; i<m; i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<bool> vis(n+1, false);
    vector<ll> par(n+1, -1);
    vector<ll> key(n+1, 1e18);
    pq.push({0, 1});
    key[1] = 0;

    while(!pq.empty()) {
        int t = pq.top().second;
        vis[t] = true;
        pq.pop();

        for(int i=0; i<adj[t].size(); i++) {

            int u = adj[t][i].first;
            int w = adj[t][i].second;

            if(!vis[u] && key[u] > w) {
                key[u] = w;
                pq.push({w, u});
                par[u] = t;
            }
        }
    }
    ll sum = 0;
    bool f = 0;
    for(int i=1; i<=n; i++) {
        if(key[i] == 1e18) {
            f = 1;
            break;
        }
        sum += key[i];
    }
    if(f) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << sum << endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
