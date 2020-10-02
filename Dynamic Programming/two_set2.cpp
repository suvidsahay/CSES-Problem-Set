#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

int power(int base, int exponent, int res) {
    if(exponent == 0) {
        return 1;
    }
    if(exponent % 2 == 1) {
        return (res * power(base, exponent / 2, (res * res) % MOD)) % MOD;
    }
    else return power(base, exponent / 2, (res * res) % MOD);
}

int mmi(int a) {
    return power(a, MOD - 2, a) % MOD;
}
 
void solve() {
    int n;
    cin >> n;
    if(n * (n + 1) % 4 != 0) {
        cout << 0 << endl;
        return;
    }
    int dp[(n * (n + 1))] = {0};
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = (n * (n + 1)) / 2; j > 0; j--) {
            dp[j] = (dp[j] + (j - i >= 0 ? dp[j - i] : 0)) % MOD;
        }
    }
    
    cout << (dp[((n * (n + 1)) / 4)] * mmi(2)) % MOD << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}