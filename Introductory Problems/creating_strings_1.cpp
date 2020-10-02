#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

vector<string> res;

bool is_complete(int freq[]) {
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            return false;
        }
    }
    return true;
}

void print_strings(int freq[], string curr_string) {
    if(is_complete(freq)) {
        res.push_back(curr_string);
        return;
    }
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            freq[i]--;
            print_strings(freq, curr_string + (char)('a' + i));
            freq[i]++;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int freq[26] = {0};

    for(int i = 0; i < s.length(); i++) {
        freq[(int)(s[i]-'a')]++;
    }

    print_strings(freq, "");

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}