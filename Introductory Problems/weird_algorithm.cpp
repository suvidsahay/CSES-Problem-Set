#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) {
            n /= 2;
        }
        else n = n * 3 + 1;
    }
    cout << 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}