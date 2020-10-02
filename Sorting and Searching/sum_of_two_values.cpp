#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int t;

    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++) {
        cin >> t;
        a.push_back({t, i});
    }

    sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    while(left < right) {
        if(a[left].first + a[right].first == x) {
            cout << a[left].second + 1 << " " << a[right].second + 1 << endl;
            return;
        }
        else if(a[left].first + a[right].first < x) {
            left++;
        }
        else right--;
    }
    
    cout << "IMPOSSIBLE" << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}