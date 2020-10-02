#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int applicants[n], apartments[m];
    for(int i = 0; i < n; i++) {
        cin >> applicants[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    sort(applicants, applicants + n);
    sort(apartments, apartments + m);

    int i = 0, j = 0;
    int count = 0;
    while(i < n && j < m) {
        if(applicants[i] - k <= apartments[j] && applicants[i] + k >= apartments[j]) {
            i++;
            j++;
            count++;
        }
        else if(applicants[i] + k < apartments[j]) {
            i++;
        }
        else j++;
    }
    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}