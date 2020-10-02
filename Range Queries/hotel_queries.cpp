#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007

using namespace std;
int n, m;

int a[200005];
int tree[800005];

void build_tree(int start, int end, int tree_node) {
    if(start == end) {
        tree[tree_node] = a[start];
        return;
    }

    int mid = (start + end) / 2; 
    build_tree(start, mid, tree_node * 2);
    build_tree(mid + 1, end, tree_node * 2 + 1);

    tree[tree_node] = max(tree[2 * tree_node], tree[2 * tree_node + 1]); 
}

int query_update(int x, int start = 0, int end = n - 1, int tree_node = 1) {
    if(start > end) {
        return -1;
    }
    if(start == end) {
        tree[tree_node] -= x;
        return start;
    }

    int mid = (start + end) / 2;
    if(tree[2 * tree_node] >= x) {
        int idx = query_update(x, start, mid, 2 * tree_node);
        tree[tree_node] = max(tree[2 * tree_node], tree[2 * tree_node + 1]);
        return idx;

    }
    else {
        int idx = query_update(x, mid + 1, end, 2 * tree_node + 1);
        tree[tree_node] = max(tree[2 * tree_node], tree[2 * tree_node + 1]);
        return idx;
    }


}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build_tree(0, n - 1, 1);

    int x;
    for(int i = 0; i < m; i++) {
        cin >> x;
        if(tree[1] < x) {
            cout << 0 << " ";
            continue;
        }
        int idx = query_update(x);
        // for(int i = 0; i < 2 * n + 1; i++) {
        //     cout << tree[i] << " ";
        // }
        // cout << endl;
        cout << idx + 1 << " ";
        // cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}