#include<bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> p;

void solve() {
    string st;
    cin >> st;
    ll m = st.length();
    ll ls[m];
    int i = 0, j = 1;
    ls[i] = 0;
    while(j < m) {
        if(st[i] == st[j]) {
            i++;
            ls[j] = i;
            j++;
        }
        else if(i == 0) {
            ls[j] = i;
            j++;
        }
        else {
            i = ls[i-1];
        }
    }
    int k = m;
    set<ll> s;
    while(k > 0) {
        if(ls[k-1] == 0) {
            break;
        }
        s.insert(ls[k-1]);
        k = ls[k-1];
    }
    for(auto j : s) {
        cout << j << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
