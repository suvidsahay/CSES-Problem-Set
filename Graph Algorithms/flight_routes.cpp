#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e15
#define MIN -1e13
 
using namespace std;

int n, m, k;
vector<array<int, 2>> G[100005];
int costs[100005], cnt[100005];
vector<int> res;

void dijstra(int root) {

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>> > pq;
    for(int i = 0; i < G[root].size(); i++) {
        pq.push({G[root][i][1], root, G[root][i][0]});
    }

    for(int i = 0; i < n; i++) {
        costs[i] = MAX;
        cnt[i] = 0;
    }

    costs[root] = 0;
    cnt[0] = 1;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if(cnt[n - 1] < k) {
            costs[top[2]] = top[0];
        }
        else break;

        if(cnt[top[2]] >= k) continue;

        if(top[2] == n - 1) {
            res.push_back(costs[n - 1]);
        }

        cnt[top[2]]++;
        for(int i = 0; i < G[top[2]].size(); i++) {
            pq.push({costs[top[2]] + G[top[2]][i][1], top[2], G[top[2]][i][0]});
        }
    }
}


void solve() {
    cin >> n >> m >> k;
    int a, b, x;
    vector<array<int, 3>> edge;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        a--;b--;
        edge.push_back({a, b, x});
        G[a].push_back({b, x});
    }

    dijstra(0);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

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