#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int x[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        if(i < a) {
            sum += x[i];
        }
    }


    for(int i = 0, j = a; i < n; i++) {
        if(x[i] < 0) {
            if(j - i == a && j < n) {
                j++;
                sum += x[j];
            }
            i++;
            sum -= x[i - 1]; 
        }
        else {
                
        }
    }

    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}