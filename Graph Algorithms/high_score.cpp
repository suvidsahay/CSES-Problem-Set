#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
#define MIN -1e13
 
using namespace std;

int n, m;
vector<int> G[2505];
vector<array<int, 3>> weights;
int cost[2505];


void dfs(vector<int> G[], int root, bool visited[]) {
    visited[root] = true;

    for(int i = 0; i < G[root].size(); i++) {
        if(!visited[G[root][i]]) {
            dfs(G, G[root][i], visited);
        }
    }
}

void solve() {
    cin >> n >> m;
    int a, b, x;
    vector<int> G[n], G_rev[n];
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        a--;b--;
        G[a].push_back(b);
        G_rev[b].push_back(a);
        weights.push_back({a, b, x});
    }

    bool visitedn[n] = {false}, visited1[n] = {false};
    dfs(G_rev, n - 1, visitedn);
    dfs(G, 0, visited1);

    bool visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = visitedn[i] & visited1[i];
    }

    for(int i = 0; i < n; i++) {
        cost[i] = MIN;
    }

    cost[0] = 0;
    int c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cost[weights[j][1]] = max(cost[weights[j][1]], cost[weights[j][0]] + weights[j][2]);
        }
    }

    for(int j = 0; j < m; j++) {
        if(visited[weights[j][1]]) {
            if(cost[weights[j][1]] != max(cost[weights[j][1]], cost[weights[j][0]] + weights[j][2])) {
                cout << -1 << endl;
                return;
            }
        }
        cost[weights[j][1]] = max(cost[weights[j][1]], cost[weights[j][0]] + weights[j][2]);
    }

    cout << cost[n - 1] << endl;
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