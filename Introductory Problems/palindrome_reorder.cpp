#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> freq;

    for(int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }

    string res = "", temp = "";
    bool flag = false;
    for(auto itr : freq) {
        if(itr.second % 2 == 1) {
            if(flag) {
                cout << "NO SOLUTION" << endl;
                return;
            }
            else {
                flag = true;
                for(int i = 0; i < itr.second; i++) {
                    temp += itr.first;
                }
            }
        }
        else {
            for(int i = 0; i < itr.second / 2; i++) {
                res += itr.first;
            }
        }
    }
    res = res + temp + string(res.rbegin(), res.rend());
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}