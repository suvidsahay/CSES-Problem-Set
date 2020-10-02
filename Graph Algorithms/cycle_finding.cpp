#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e15
#define MIN -1e13
 
using namespace std;

int n, m;
vector<array<int, 3>> edges;


void solve() {
    cin >> n >> m;
    int a, b, x;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        a--;b--;
        edges.push_back({a, b, x});
    }

    int costs[n];
    for(int i = 0; i < n; i++) {
        costs[i] = MAX;
    }
    costs[0] = 0;

    int par[n];
    par[0] = -1;

    bool cycle = false;
    int cycle_vertex;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(costs[edges[j][1]] > costs[edges[j][0]] + edges[j][2]) {
                costs[edges[j][1]] = costs[edges[j][0]] + edges[j][2];
                par[edges[j][1]] = edges[j][0];
            }
        }
    }

    for(int j = 0; j < m; j++) {
        if(costs[edges[j][1]] > costs[edges[j][0]] + edges[j][2]) {
            cycle = true;
            cycle_vertex = edges[j][1];
            costs[edges[j][1]] = costs[edges[j][0]] + edges[j][2];
            par[edges[j][1]] = edges[j][0];
        }
    }

    if(cycle) {
        cout << "YES" << endl;
        
        set<int> cycles;
        
        while(cycles.find(cycle_vertex) == cycles.end()) {
            cycles.insert(cycle_vertex);
            cycle_vertex = par[cycle_vertex];
        }
        vector<int>cycle_path;
        cycle_path.push_back(cycle_vertex + 1);
        int root = cycle_vertex;
        cycle_vertex = par[cycle_vertex];
        while(cycle_vertex != root) {
            cycle_path.push_back(cycle_vertex + 1);
            cycle_vertex = par[cycle_vertex];
        }
        cycle_path.push_back(cycle_vertex + 1);
        reverse(cycle_path.begin(), cycle_path.end());
        for(int i = 0; i < cycle_path.size(); i++) {
            cout << cycle_path[i] << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;
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