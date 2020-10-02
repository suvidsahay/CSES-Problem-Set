#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int a;
    for(int i = 0; i < n - 1; i++) {
        cin >> a;
        sum += a;
    }

    cout << (n * (n + 1)) / 2 - sum << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}