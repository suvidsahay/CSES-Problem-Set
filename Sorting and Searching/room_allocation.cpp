#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x;
    vector<array<int, 3>> vec;
    for(int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back({i, x, 1});
        cin >> x;
        vec.push_back({i, x, -1});
    }

    sort(vec.begin(), vec.end(), [](const array<int, 3>& a, const array<int,3>& b) {
        if(a[1] != b[1]) {
            return a[1] < b[1];
        }
        else return b[2] < a[2];
    });

    int count = 0;
    map<int, int> rooms;
    set<int> emp;
    int room = 1;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i][2] == 1) {
            if(emp.empty()) {
                rooms[vec[i][0]] = room;
                room++;
            }
            else {
                rooms[vec[i][0]] = *emp.begin();
                emp.erase(emp.begin());
            }
        }
        else {
            emp.insert(rooms[vec[i][0]]);
        }
        
    }
    cout << room - 1 << endl;
    for(int i = 0; i < n; i++) {
        cout << rooms[i] << " ";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}