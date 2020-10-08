#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 19; // 2 ^ maxN is the maximum height of the tree.
const int N = 2e5 + 5;
vector<int> adj[N];
int level[N];
int ancestor[N][maxN + 2]; // this sparse matrix saves all the 2th power ancestors of the node, like - 0, 1, 2, 4, 8...

void dfs(int node, int par, int h) {
        level[node] = h;
        ancestor[node][0] = par;
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
                        if(ancestor[j][i - 1] != -1) {
                                int par = ancestor[j][i - 1];
                                ancestor[j][i] = ancestor[par][i - 1]; // current node's ith ancestor = parent node's (i - 1)th ancestor.
                        }
                }
        }
}

int getNode(int a, int d) {
        if(level[a] < d)
                return -1;
        for(int i = maxN; i >= 0; i--) {
                if(d >= (1 << i)) {
                        a = ancestor[a][i]; // binary lifting
                        d -= (1 << i);
                }
        }
        return a;
}



void solve() {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= maxN; j++) {
                        ancestor[i][j] = -1;
                }
        }
        int v = 2;
        for(int i = 0; i < n - 1; i++) {
                int u;
                cin >> u;
                adj[u].push_back(v);
                adj[v].push_back(u);
                v++;
        }
        preProcess(n);
        while(q--) {
                int a, d;
                cin >> a >> d;
                cout << getNode(a, d) <<"\n";
        }
}




signed main() {
        solve();
        return 0;
}


