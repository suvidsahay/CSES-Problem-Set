#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
#define MAX 1e13
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    set<int> s;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(s.lower_bound(x) != s.end()) {
            s.erase(s.lower_bound(x));
        }
        s.insert(x);
    }
    cout << s.size() << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}