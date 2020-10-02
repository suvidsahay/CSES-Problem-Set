#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<int> G[100005];
int parent[100005];
int n, m;
vector<int> path;
 
void get_parent(int root) {
    if(root == -1) {
        return;
    }
    path.push_back(root);
    get_parent(parent[root]);
    
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

    queue<int> nodes;
    nodes.push(0);

    bool visited[n];
    memset(visited, false, sizeof(visited));
    parent[0] = -1;
    visited[0] = true;
    while(!nodes.empty()) {
        int next = nodes.front();
        nodes.pop();
        if(next == n - 1) {
            get_parent(n - 1);
            cout << path.size() << endl;
            for(int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] + 1 << " ";
            }
            cout << endl;
            return;
        }

        for(int i = 0; i < G[next].size(); i++) {
            if(!visited[G[next][i]]) {
                nodes.push(G[next][i]);
                visited[G[next][i]] = true;
                parent[G[next][i]] = next;
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