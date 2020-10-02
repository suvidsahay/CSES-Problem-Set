#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<array<int, 2>> G[100005];
 
void solve() {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(int i = 0; i < G[0].size(); i++) {
        pq.push({G[0][i][1], 0, G[0][i][0]});
    }
    bool visited[n] = {false};
    int dist[n];
    int paths[n], min_path[n], max_path[n];
    for(int i = 0; i < n; i++) {
        dist[i] = INT64_MAX;
        paths[i] = 0;
        min_path[i] = INT64_MAX;
        max_path[i] = 0;
    }
    dist[0] = 0;
    visited[0] = true;
    paths[0] = 1;
    min_path[0] = max_path[0] = 0;
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if(dist[top[2]] >= top[0]) {
            dist[top[2]] = top[0];
            paths[top[2]] = (paths[top[2]] + paths[top[1]]) % MOD;
            min_path[top[2]] = min(min_path[top[2]], 1 + min_path[top[1]]);
            max_path[top[2]] = max(max_path[top[2]], 1 + max_path[top[1]]);
        }
        // cout << top[0] << " " << top[1] + 1 << " " << top[2] + 1 << " " << top[3] << endl;
        // if(top[2] == n - 1) {
        //     if(min_dist > top[0]) {
        //         min_dist = top[0];
        //         paths = 1;
        //         min_path = max_path = top[3];
        //     }
        //     else if(min_dist == top[0]) {
        //         paths++;
        //         min_path = min(min_path, top[3]);
        //         max_path = max(max_path, top[3]);
        //     } 
        // }
        if(visited[top[2]]) {
            continue;
        }
        else {
            visited[top[2]] = true;
            dist[top[2]] = min(dist[top[2]], top[0]);
            for(int i = 0; i < G[top[2]].size(); i++) {
                pq.push({dist[top[2]] + G[top[2]][i][1], top[2], G[top[2]][i][0]});
            }
        }
    }

    cout << dist[n - 1] << " " << paths[n - 1] << " " << min_path[n - 1] << " " << max_path[n - 1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}