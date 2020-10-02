#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;

int getMax(int n) {
    int res = 0;
    while(n) {
        res = max(res, n % 10);
        n /= 10;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    int count = 0;
    while(n) {
        n -= getMax(n);
        count ++;
    }

    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}