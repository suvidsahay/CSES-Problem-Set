#include <bits/stdc++.h>
 
#define int long long
#define MOD 1000000007

using namespace std;
int n, q;

void build_tree(int a[], int tree[], int start, int end, int idx) {
    if(start == end) {
        tree[idx] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build_tree(a, tree, start, mid, idx * 2);
    build_tree(a, tree, mid + 1, end, idx * 2 + 1);

    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int query(int tree[], int l, int r, int start = 0, int end = n - 1, int idx = 1) {
    if(l > end || r < start) {
        return 0;
    }
    if(l <= start && r >= end) {
        return tree[idx];
    }
    else {
        int mid = (start + end) / 2;
        return query(tree, l, r, start, mid, idx * 2) + query(tree, l, r, mid + 1, end, idx * 2 + 1);
    }
}

void solve() {
    
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int tree[4 * n] = {0};
    build_tree(a, tree, 0, n - 1, 1);

    // for(int i = 0; i < 4 * n; i++) {
    //     cout << tree[i] << " ";
    // }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(tree, l - 1, r - 1) << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}