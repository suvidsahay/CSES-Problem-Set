#include<bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> pq;
ll p = -1, q = -1;

void dfs(int i, vector<ll> adj[], stack<ll>& st, vector<bool>& vis) {
    vis[i] = 1;
    for(int j=0; j<adj[i].size(); j++) {
        if(!vis[adj[i][j]]) {
            dfs(adj[i][j], adj, st, vis);
        }
    }
    st.push(i);
}
void dfs1(int k, vector<ll> tadj[], vector<bool>& vis, int flag) {
    if(flag == 0) {
        p = k;
    }
    vis[k] = 1;
    for(int j=0; j<tadj[k].size(); j++) {
        if(!vis[tadj[k][j]]) {
            dfs1(tadj[k][j], tadj, vis, flag);
        }
    }
}
void solve() {
    ll n, m;
    cin >> n >> m;
    ll x, y;
    vector<ll> adj[n+1];
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    stack<ll> st;
    vector<bool> vis(n+1);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, adj, st, vis);
        }
    }
    for(int i=1; i<=n; i++) {
        vis[i] = 0;
    }
    ll cnt = 0;
    vector<ll> tadj[n+1]; //transpose
    for(int i=1; i<=n; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            tadj[adj[i][j]].push_back(i);
        }
    }
    while(!st.empty()) {
        int k = st.top();
        st.pop();
        if(!vis[k]) {
            if(cnt == 1) {
                q = k;
            }
            if(cnt == 0) {
                dfs1(k, tadj, vis, 0);
            }
            else {
                dfs1(k, tadj, vis, 1);
            }
            cnt++;
        }
    }
    if(cnt == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
        cout << q << " " << p << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
