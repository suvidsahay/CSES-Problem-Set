#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<int> G[100005];
int n, m;
bool visited[100005];
int parent[100005];
vector<int> paths;

void print_parent(int root, int par) {
    if(root == par) {
        paths.push_back(par);
    }
    else {
        paths.push_back(root);
        print_parent(parent[root], par);
    }
}

bool dfs(int root, int par) {
    visited[root] = true;
    for(int i = 0; i < G[root].size(); i++) {
        if(visited[G[root][i]] && G[root][i] != par) {
            print_parent(root, G[root][i]);
            return true;
        }
        else if(!visited[G[root][i]]){
            parent[G[root][i]] = root;
            if(dfs(G[root][i], root)) {
                return true;
            }
        }
    }
    return false;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            parent[i] = -1;
            if(dfs(i, -1)) {
                cout << paths.size() + 1 << endl;
                for(int i = paths.size() - 1; i >= 0; i--) {
                    cout << paths[i] + 1 << " ";
                }
                cout << paths[paths.size() - 1] + 1 << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}