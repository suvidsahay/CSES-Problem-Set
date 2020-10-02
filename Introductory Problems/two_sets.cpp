#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n % 4 != 0 && n % 4 != 3) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(n % 4 == 0) {
        cout << n / 2 << endl;
        for(int i = 1; i <= n / 4; i++) {
            cout << i << " " << n - i  + 1 << " ";
        }
        cout << endl;
        cout << n / 2 << endl;
        for(int i = n / 4 + 1; i <= n / 2; i++) {
            cout << i << " " << n - i + 1 << " ";
        }
        cout << endl;

    }
    if(n % 4 == 3) {
        cout << n / 2 + 1 << endl;
        cout << "1 2 ";
        for(int i = 4; i <= 3 + n / 4; i++) {
            cout << i << " " << n - i + 4 << " ";
        }
        cout << endl;
        cout << n / 2 << endl << 3 << " ";
        for(int i = 4 + n / 4; i < 3 + n / 2; i++) {
            cout << i << " " << n - i + 4 << " ";
        }
        cout << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}