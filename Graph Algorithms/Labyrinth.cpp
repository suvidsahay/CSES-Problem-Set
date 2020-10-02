#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<pair<char, array<int, 2>>> paths = {{'R',{0, 1}}, {'L', {0, -1}}, {'D',{1, 0}}, {'U', {-1, 0}}};
pair<int, int> start, dest;
char a[1005][1005];
int n, m;
string res = "";
map<pair<int, int>, pair<pair<int, int>, char>> parent;

void getParent(pair<int, int> p) {
    if(p.first == -1 && p.second == -1) {
        return;
    }
    else res += parent[p].second;

    getParent(parent[p].first);
}

bool isPossible(int row, int col) {
    if(row < 0 || row >= n || col < 0 || col >= m || a[row][col] == '#') {
        return false;
    }
    return true;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                start.first = i;
                start.second = j;
                a[i][j] = '#';
            }
            if(a[i][j] == 'B') {
                dest.first = i;
                dest.second = j;
            }
        }
    }

    queue<array<int, 2>> bfs;
    
    parent[start] = {{-1, -1}, 'N'};
    bfs.push({start.first, start.second});
    while(!bfs.empty()) {
        auto next = bfs.front();
        if(next[0] == dest.first && next[1] == dest.second) {
            cout << "YES" << endl;
            getParent({next[0], next[1]});
            res = res.substr(0, res.size() - 1);

            cout << res.size() << endl << string(res.rbegin(), res.rend()) << endl;
            return;
        }

        bfs.pop();
        for(int i = 0; i < paths.size(); i++) {
            if(isPossible(next[0] + paths[i].second[0], next[1] + paths[i].second[1])) {
                bfs.push({next[0] + paths[i].second[0], next[1] + paths[i].second[1]});
                a[next[0] + paths[i].second[0]][next[1] + paths[i].second[1]] = '#';
                parent[{next[0] + paths[i].second[0], next[1] + paths[i].second[1]}] = {{next[0], next[1]}, paths[i].first};
            }
        }
    }

    cout << "NO" << endl;
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