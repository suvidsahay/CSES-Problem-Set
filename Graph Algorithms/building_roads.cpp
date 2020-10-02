#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<int> G[100005];
int n, m;
bool visited[100005];
set<set<int>> components;
set<int> component;

void dfs(int root) {
    component.insert(root);
    visited[root] = true;
    for(int i = 0; i < G[root].size(); i++) {
        if(!visited[G[root][i]]) {
            dfs(G[root][i]);
        }
    }
}

void get_components() {
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            components.insert(component);
            component.clear();
        }
    }
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
    get_components();
    
    int first = *(components.begin()->begin());
    auto itr = components.begin();

    itr++;
    cout << components.size() - 1 << endl;
    for(;itr != components.end(); itr++) {
        cout << first + 1 << " " << (*itr->begin()) + 1 << endl;
    }
}
 
int32_t main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}