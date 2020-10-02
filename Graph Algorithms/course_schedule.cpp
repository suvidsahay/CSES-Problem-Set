#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<int> G[100005];
int n, m;
bool visited[100005];
vector<int> nodes;

bool dfs(int root, set<int>& path) {
    visited[root] = true;
    path.insert(root);
    for(int i = 0; i < G[root].size(); i++) {
        if(path.find(G[root][i]) != path.end()) {
            return false;
        }
        if(!visited[G[root][i]]) {
            if(!dfs(G[root][i], path)) {
                return false;
            }
            path.erase(G[root][i]);
        }
    }
    nodes.push_back(root);
    return true;
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

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            set<int> path;
            if(!dfs(i, path)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for(int i = nodes.size() - 1; i >= 0; i--) {
        cout << nodes[i] + 1 << " ";
    }
    cout << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}