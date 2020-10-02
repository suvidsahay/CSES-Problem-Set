#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e15
#define MIN -1e13
 
using namespace std;

int n, m;
vector<array<int, 2>> G[100005], G_rev[100005];
int costs[100005], costs_rev[100005];

void dijstra(vector<array<int, 2>> G[], int costs[], int root) {
    set<int> visited;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>> > pq;
    for(int i = 0; i < G[root].size(); i++) {
        pq.push({G[root][i][1], root, G[root][i][0]});
    }

    for(int i = 0; i < n; i++) {
        costs[i] = MAX;
    }

    costs[root] = 0;
    visited.insert(root);

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if(visited.find(top[2]) == visited.end()) {
            costs[top[2]] = min(costs[top[2]], top[0]);
        }
        else continue;

        visited.insert(top[2]);
        for(int i = 0; i < G[top[2]].size(); i++) {
            pq.push({costs[top[2]] + G[top[2]][i][1], top[2], G[top[2]][i][0]});
        }
    }
}


void solve() {
    cin >> n >> m;
    int a, b, x;
    vector<array<int, 3>> edge;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        a--;b--;
        edge.push_back({a, b, x});
        G[a].push_back({b, x});
        G_rev[b].push_back({a, x});
    }

    dijstra(G, costs, 0);
    dijstra(G_rev, costs_rev, n - 1);

    int cost = MAX;

    for(int i = 0; i < m; i++) {
        cost = min(cost, costs[edge[i][0]] + costs_rev[edge[i][1]] + edge[i][2] / 2);
    }

    cout << cost << endl;
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