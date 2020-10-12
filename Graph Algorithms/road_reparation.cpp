#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<array<int, 3>> roads;
int n, m;
bool visited[100005];
int parent[100005];

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_find(int x, int y) {
    int x_par = find(x);
    int y_par = find(y);
    if(x_par != y_par) {
        parent[x_par] = y_par;
    }
}

int MST() {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        visited[i] = false;
    }
    sort(roads.begin(), roads.end());
    int cost = 0;
    for(int i = 0; i < roads.size(); i++) {
        if(find(roads[i][1]) != find(roads[i][2])) {
            cost += roads[i][0];
            union_find(roads[i][1], roads[i][2]);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(parent[i] == i) {
            count++;
        }
    }
    if(count > 1) {
        return -1;
    }
    return cost;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        roads.push_back({c, a, b});
    }
    int res = MST();
    if(res == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else cout << res << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}