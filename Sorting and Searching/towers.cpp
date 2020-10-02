#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    vector<int> towers;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        auto itr = upper_bound(towers.begin(), towers.end(), a[i]);
        if(itr == towers.end()) {
            towers.push_back(a[i]);  
        }
        else if(*itr == a[i]) {
            towers.insert(itr, a[i]);
        }
        else *itr = a[i];
    }
    cout << towers.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}