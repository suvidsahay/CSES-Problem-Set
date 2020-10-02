#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre;
    pre.push_back(0);
    for(int i = 0; i < n; i++) {
        pre.push_back(pre[i] + a[i]);
    }
    int l = 0, h = 0;
    int count = 0;
    while(h <= n) {
        if(pre[h] - pre[l] < x) {
            h++;
        }
        else if(pre[h] - pre[l] > x) {
            l++;
        }
        else {
            count++;
            l++; h++;
        }
    }

    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}