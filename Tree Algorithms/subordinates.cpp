#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007

using namespace std;
int n, q;
vector<int> G[200005];
int childs[200005];

int dfs(int root) {
    int c = 0;
    for(int i = 0; i < G[root].size(); i++) {
        c += dfs(G[root][i]);
    }
    childs[root] = c;
    return c + 1;
}

void solve() {
    
    cin >> n;
    int x;
    for(int i = 0; i < n - 1; i++) {
        cin >> x;
        G[x - 1].push_back(i + 1);
    }

    dfs(0);
    for(int i = 0; i < n; i++) {
        cout << childs[i] << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}