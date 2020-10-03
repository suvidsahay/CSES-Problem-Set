#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, x = 0, y;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> y, x ^= y;
    cout << (x == 0 ? "second\n" : "first\n");
  }

  return 0;
}