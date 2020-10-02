#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<int> G[100005];
int color[100005];
int n, m;
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    
    memset(color, 0, sizeof(color));
    for(int v = 0; v < n; v++) {
        if(color[v] == 0) {
            queue<pair<int, int>> nodes;
            nodes.push({v, 1});
            color[v] = 1;
            while(!nodes.empty()) {
                auto next = nodes.front();
                nodes.pop();
                
                for(int i = 0; i < G[next.first].size(); i++) {
                    if(color[G[next.first][i]] == 0) {
                        nodes.push({G[next.first][i], (next.second % 2) + 1});
                        color[G[next.first][i]] = (next.second % 2) + 1;
                    }
                    else {
                        if(color[G[next.first][i]] != ((next.second % 2) + 1)) {
                            cout << "IMPOSSIBLE" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}