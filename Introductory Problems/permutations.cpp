#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
    }
    else if(n <= 3) {
        cout << "NO SOLUTION" << endl; 
    }
    else if(n == 4) {
        cout << "2 4 1 3" << endl;
    }
    else {
        for(int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for(int j = 2; j <= n; j += 2) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}