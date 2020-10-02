#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        a.push_back({t, i});
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        int l = i + 1, h = n - 1;
        while(l < h) {
            int sum = a[i][0] + a[l][0] + a[h][0];
            if(sum > x) {
                h--;
            }
            else if(sum < x) {
                l++;
            }
            else {
                cout << a[i][1] + 1 << " " << a[l][1] + 1 << " " << a[h][1] + 1 << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}