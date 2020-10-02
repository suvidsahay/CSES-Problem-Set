#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

vector<array<int, 2>> paths = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char a[1005][1005];
int n, m;

bool isPossible(int row, int col) {
    if(row < 0 || row > n || col < 0 || col > m) {
        return false;
    }
    return true;
}

void dfs(int row, int col) {
    a[row][col] = '#';
    for(int i = 0; i < paths.size(); i++) {
        if(a[row + paths[i][0]][col + paths[i][1]] == '.' && isPossible(row + paths[i][0], col + paths[i][1])){
            dfs(row + paths[i][0],col + paths[i][1]);
        }
    }
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.') {
                count++;
                dfs(i, j);
            }
        }
    }

    cout << count << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}