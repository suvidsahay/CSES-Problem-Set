#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

int res = 0;

bool empty(bool grid[7][7], int r, int c) {
    if(r < 0 || r >= 7 || c < 0 || c >= 7) {
        return false;
    }
    if(grid[r][c]) {
        return false;
    }
    return true;
}

void get_paths(bool grid[7][7], string& s, int r, int c, int idx) {
    // cout << r << " " << c << " " << idx << " " << res << endl;

    if(r == 6 && c == 0) {
        if(idx == 48) {
            res++;
        }
        return;
    }

    grid[r][c] = true;

    if(s[idx] == '?' || s[idx] == 'U') {
        if(empty(grid, r - 1, c) && !(!empty(grid, r - 2, c) && empty(grid, r - 1, c - 1) && empty(grid, r - 1, c + 1)))
        get_paths(grid, s, r - 1, c, idx + 1);
    }

    if(s[idx] == '?' || s[idx] == 'D') {
        if(empty(grid, r + 1, c) && !(!empty(grid, r + 2, c) && empty(grid, r + 1, c - 1) && empty(grid, r + 1, c + 1)))
        get_paths(grid, s, r + 1, c, idx + 1);
    }

    if(s[idx] == '?' || s[idx] == 'L') {
        if(empty(grid, r, c - 1) && !(!empty(grid, r, c - 2) && empty(grid, r - 1, c - 1) && empty(grid, r + 1, c - 1)))
        get_paths(grid, s, r, c - 1, idx + 1);
    }

    if(s[idx] == '?' || s[idx] == 'R') {
        if(empty(grid, r, c + 1) && !(!empty(grid, r, c + 2) && empty(grid, r - 1, c + 1) && empty(grid, r + 1, c + 1)))
        get_paths(grid, s, r, c + 1, idx + 1);
    }
    
    grid[r][c] = false;
}

void solve() {
    string s;
    cin >> s;
    bool grid[7][7] = {0};
    get_paths(grid, s, 0, 0, 0);
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}