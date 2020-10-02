#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<pair<int, int>> temp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i < k) {
            temp.push_back({a[i], i});
        }
    }
    if(k == 1) {
        for(int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }

    sort(temp.begin(), temp.end());
    set<pair<int, int>> p1, p2;

    for(int i = 0; i < k; i++) {
        if(i < k / 2) p1.insert(temp[i]); 
        else p2.insert(temp[i]);
    }

    pair<int,int> median;
    if(k % 2 == 1) {
        median = ((p1.size() > p2.size()) ? *p1.rbegin() : *p2.begin());
        
    }
    else {
        median = *p1.rbegin();
    }

    int cost = 0;
    for(int i = 0; i < k; i++) {
        cost += abs(a[i] - median.first);
    }
    cout << cost << " ";
    // cout << endl;
    // for(auto itr : p1) {
    //     cout << "{" << itr.first << "," << itr.second <<"}";
    //     cout << ",";
    // }
    // cout << endl;
    // for(auto itr : p2) {
    //     cout << "{" << itr.first << "," << itr.second <<"}";
    //     cout << ",";
    // }
    // cout << endl;
    // cout <<  (p1.rbegin()->second) << " " << p2.begin()->first << endl;
    for(int i = k; i < n; i++) {
        
        if(a[i] < p1.rbegin()->first) {
            p1.insert({a[i], i});
        }
        else {
            p2.insert({a[i], i});
        }

        if(p1.find({a[i - k], i - k}) != p1.end()) {
            p1.erase({a[i - k], i - k});
        }
        else if(p2.find({a[i - k], i - k}) != p2.end()) {
            p2.erase({a[i - k], i - k});
        }

        cost -= abs(a[i - k] - median.first);

        if(abs((int)p1.size() - (int)p2.size()) >= 2) {
            if(p1.size() > p2.size()) {
                p2.insert(*p1.rbegin());
                p1.erase(*p1.rbegin());
            }
            else {
                p1.insert(*p2.begin());
                p2.erase(*p2.begin());
            }
        }
        pair<int, int> prev_median = median;
        if(k % 2 == 1) {
            median =  ((p1.size() > p2.size()) ? *p1.rbegin() : *p2.begin());
        }
        else {
            median = *p1.rbegin();
        }

        if(prev_median.first > median.first) {
            if(p2.find(median) == p2.end()) {
                cost += p2.size() * abs(prev_median.first - median.first);
                cost -= (p1.size() - 1) * abs(prev_median.first - median.first);
            }
            else {
                cost += (p2.size() - 1) * abs(prev_median.first - median.first);
                cost -= p1.size() * abs(prev_median.first - median.first);
            }
            
        }
        else {
            if(p2.find(median) == p2.end()) {
                cost -= p2.size() * abs(prev_median.first - median.first);
                cost += (p1.size() - 1) * abs(prev_median.first - median.first);
            }
            else {
                cost -= (p2.size() - 1) * abs(prev_median.first - median.first);
                cost += p1.size() * abs(prev_median.first - median.first);
            }
        }

        cost += abs(a[i] - median.first);
        cout << cost << " ";   
    }

    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}