#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e14
 
using namespace std;
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int x, y, z;
    int dist[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = MAX;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        x--; y--;
        dist[x][y] = min(z, dist[x][y]);
        dist[y][x] = min(z, dist[y][x]);
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        if(dist[x - 1][y - 1] >= MAX) {
            cout << -1 << endl;
        }
        else cout << dist[x - 1][y - 1] << endl;
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