#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, x;
    cin >> n;

    map<int, int> freq;
    freq[0]++;
    int a[n];
    int sum = 0, count = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum = (((sum + a[i]) % n) + n) % n;
        if(freq.find(sum) != freq.end()) {
            count += freq[sum];
        }
        freq[sum]++;
    }
    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}