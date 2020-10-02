#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007

using namespace std;
int n, m;

int a[200005];
int tree[800005];
int present[200005];

void build_tree(int start, int end, int tree_node) {
    if(start == end) {
        tree[tree_node] = present[start];
        return;
    }

    int mid = (start + end) / 2; 
    build_tree(start, mid, tree_node * 2);
    build_tree(mid + 1, end, tree_node * 2 + 1);

    tree[tree_node] = tree[2 * tree_node] + tree[2 * tree_node + 1]; 
}

int query(int l, int r, int start = 0, int end = n - 1, int tree_node = 1) {
    if(end < l || start > r) {
        return 0;
    }
    if(l <= start && r >= end) {
        return tree[tree_node];
    }
    int mid = (start + end) / 2;
    return query(l, r, start, mid, tree_node * 2) + query(l, r, mid + 1, end, tree_node * 2 + 1);

}

void update(int x, int start = 0, int end = n - 1, int tree_node = 1) {
    if(start > end || end < x || start > x) {
        return;
    }
    if(start == end) {
        tree[tree_node] = 0;
        present[start] = 0;
        return;
    }
    int mid = (start + end) / 2;
    update(x, start, mid, tree_node * 2);
    update(x, mid + 1, end, tree_node * 2 + 1);
    tree[tree_node] = tree[2 * tree_node] + tree[2 * tree_node + 1];
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        present[i] = 1;
    }
    build_tree(0, n - 1, 1);

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        int low = 0, high = n - 1;
        int mid = 0;
        while(low <= high) {
            int m = (low + high) / 2;
            int sum = query(0, m);
            if(sum > x) {
                high = m - 1;
            }
            else if(sum < x) {
                low = m + 1;
            }
            else {
                high = m - 1;
                mid = m;
            }
            // cout << sum << " " << mid << endl;
        }
        cout << a[mid] << " ";
        update(mid);
        // cout << endl << mid << endl;
        // for(int i = 0; i < 2 * n; i++) {
        //     cout << tree[i] << " ";
        // }
        // cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}