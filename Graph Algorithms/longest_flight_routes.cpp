#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<int> G[100005];
int n, m;
bool visited[100005];
int par[100005] = {-1};

void dfs(int root, vector<int>& path) {
    visited[root] = true;
    for(int i = 0; i < G[root].size(); i++) {
        if(!visited[G[root][i]]) {
            dfs(G[root][i], path);
        }
    }
    path.push_back(root);
}

void print_parent(int root) {
    if(root == -1) {
        return;
    }
    print_parent(par[root]);
    cout << root + 1 << " ";
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
    

    vector<int> nodes;
    dfs(0, nodes);
    if(!visited[n - 1]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(nodes.begin(), nodes.end());
    int dist[n];
    for(int i = 0; i < n; i++) {
        dist[i] = 1;
    }
    
    for(int i = 0; i < nodes.size(); i++) {
        for(int j = 0; j < G[nodes[i]].size(); j++) {
            if (dist[G[nodes[i]][j]] < dist[nodes[i]] + 1) {
                dist[G[nodes[i]][j]] = dist[nodes[i]] + 1;
                par[G[nodes[i]][j]] = nodes[i];
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    cout << dist[n - 1] << endl;
    print_parent(n - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}