#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, x;
    cin >> x >> n;
    int a[n];
    set<int> pos;
    pos.insert(0);
    pos.insert(x);
    map<int, int> length;
    length[x]++;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        auto l = pos.upper_bound(a[i]);
        auto h = l--;
        pos.insert(a[i]);

        int size = *h - *l;
        length[size]--;
        if(length[size] == 0) {
            length.erase(size);
        }
        length[a[i] - *l]++;
        length[*h - a[i]]++;

        cout << length.rbegin()->first << endl; 
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}