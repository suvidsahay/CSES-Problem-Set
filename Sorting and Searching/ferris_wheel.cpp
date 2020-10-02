#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int weights[n];
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights, weights + n);

    int i = 0, j = n - 1;
    int count = 0;

    while(i <= j) {
        if(weights[i] + weights[j] <= x) {
            j--; i++;
        }
        else j--;
        count++;
    }

    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}