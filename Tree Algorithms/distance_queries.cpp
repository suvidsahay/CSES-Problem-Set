#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 19; // 2 ^ maxN is the maximum height of the tree.
const int N = 2e5 + 5;
vector<int> adj[N];
int level[N];
int LCA[N][maxN + 2];

void dfs(int node, int par, int h) {
        level[node] = h;
        LCA[node][0] = par;
        for(auto child : adj[node]) {
                if(child != par) {
                        dfs(child, node, h + 1);
                }
        }
}

void preProcess(int n) {
        dfs(1, 0, 0);
        for(int i = 1; i <= maxN; i++) {
                for(int j = 1; j <= n; j++) {
                        if(LCA[j][i - 1] != -1) {
                                int par = LCA[j][i - 1];
                                LCA[j][i] = LCA[par][i - 1]; // current node's ith parent = parent node's (i - 1)th parent.
                        }
                }
        }
}

int getLCA(int a, int b) {
        if(level[a] > level[b])
                swap(a, b);
        int dif = level[b] - level[a];
        while(dif > 0) { // jump until level[b] > level[a]
                int temporary_jump = log2(dif);
                b = LCA[b][temporary_jump];
                dif -= (1 << temporary_jump);
        }
        // now both the nodes are in the same level
        if(a == b)
                return a;
        for(int i = maxN; i >= 0; i--) {
                if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])) {
                        a = LCA[a][i];
                        b = LCA[b][i];
                }
        }
        return LCA[a][0];
}

int getDistance(int a, int b) {
        int lca = getLCA(a, b);
        int distance = level[a] + level[b] - 2 * level[lca];
        return distance;
}

void solve() {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= maxN; j++) {
                        LCA[i][j] = -1;
                }
        }
        for(int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        preProcess(n);
        while(q--) {
                int a, b;
                cin >> a >> b;
                cout << getDistance(a, b) <<"\n";
        }
}



signed main() {
        solve();
        return 0;
}


