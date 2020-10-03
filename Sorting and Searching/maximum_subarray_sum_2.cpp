#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define inf ((ll)1e18 + 1)

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll ar[n];
    ll maxi_sum = -inf;
    for (int x = 0; x < n; x++)
    {
        cin >> ar[x];
    }
    ll pref[n + 1];
    pref[0] = 0;
    for (int x = 1; x <= n; x++)
    {
        pref[x] = pref[x - 1] + ar[x - 1];
    }
    deque<ll> dq;
    for (ll x = a; x <= n; x++)
    {
        if (!dq.empty() && x - dq.front() > b)
        {
            dq.pop_front();
        }
        while (!dq.empty() && pref[x - a] <= pref[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(x - a);
        maxi_sum = max(maxi_sum, pref[x] - pref[dq.front()]);
    }
    cout << maxi_sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
