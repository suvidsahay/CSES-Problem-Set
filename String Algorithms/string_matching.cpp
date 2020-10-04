#include<bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> p;

void solve() {
    string st, pat;
    cin >> st >> pat;
    ll n = st.length();
    ll m = pat.length();
    ll ls[m];
    int i = 0, j = 1;
    ls[i] = 0;
    while(j < m) {
        if(pat[i] == pat[j]) {
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
    int a = 0, b = 0;
    ll cnt = 0;
    while(a < n) {
        if(st[a] == pat[b]) {
            a++;
            b++;
        }
        if(b == m) {
            cnt++;
            b = ls[b-1];
        }
        else if(st[a] != pat[b]) {
            if(b == 0) {
                a++;
            }
            else {
                b = ls[b-1];
            }
        }
    }
    cout << cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
