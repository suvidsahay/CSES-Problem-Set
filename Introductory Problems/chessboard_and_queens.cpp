#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

int res = 0;

bool can_place(char chess[][8], int board[8][8], int r, int c) {
    if(chess[r][c] == '*') {
        return false;
    }

    for(int i = 0; i < 8; i++) {
        if(board[i][c] == 1) {
            return false;
        }
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 1 && abs(r - i) == abs(c - j)) {
                return false;
            } 
        }
    }
    return true;
}

void count_perm(char chess[][8], int board[8][8], int level) {
    if(level == 8) {
        res++;
        return;
    }
    for(int i = 0; i < 8; i++) {
        if(can_place(chess, board, level, i)) {
            board[level][i] = 1;
            count_perm(chess, board, level + 1);
            board[level][i] = 0;
        }
    }
}

void solve() {
    char chess[8][8];
    int board[8][8] = {0};
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }
    count_perm(chess, board, 0);
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}