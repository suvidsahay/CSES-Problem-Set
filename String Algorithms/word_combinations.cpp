#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define mod 1000000007

struct Node
{
    Node *child[26];
    bool end;
    Node()
    {
        for (int x = 0; x < 26; x++)
        {
            child[x] = NULL;
        }
        end = false;
    }
};

void insert(Node *root, string &str, int idx)
{
    if (idx == str.length())
    {
        root->end = true;
        return;
    }
    if (root->child[str[idx] - 'a'] == NULL)
    {
        root->child[str[idx] - 'a'] = new Node();
    }
    root = root->child[str[idx] - 'a'];
    insert(root, str, idx + 1);
}

void solve()
{
    Node *root = new Node();
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    for (int x = 0; x < k; x++)
    {
        string dic;
        cin >> dic;
        insert(root, dic, 0);
    }
    ll dp[n + 1];
    dp[n] = 1;
    for (int x = n - 1; x >= 0; x--)
    {
        dp[x] = 0;
        Node *tmp = root;
        for (int y = x; y < n; y++)
        {
            if (tmp->child[s[y] - 'a'] != NULL)
            {
                tmp = tmp->child[s[y] - 'a'];
                if (tmp->end)
                {
                    dp[x] += dp[y + 1];
                    dp[x] %= mod;
                }
            }
            else
            {
                break;
            }
        }
    }
    cout << dp[0] << endl;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}