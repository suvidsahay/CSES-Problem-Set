#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    string s;
    cin >> s;
    int count = 0, res = 0;
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]) {
            count ++;
        }
        else {
            res = max(res, count + 1);
            count = 0;
        }
    }
    res = max(res, count + 1);
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}