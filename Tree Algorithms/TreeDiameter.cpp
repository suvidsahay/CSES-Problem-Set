#include <bits/stdc++.h>

using namespace std;

vector<int> v[200001]; // adjacency list for storing tree

int maxd = INT_MIN; //it stores maximum distance from source node

int ans, temp;

void dfs(int node, int par, int depth)
{
  if (depth > maxd)
    maxd = depth, temp = node;

  for (int i = 0; i < v[node].size(); ++i)
  {
    int k = v[node][i];
    if (k == par)
      continue;

    dfs(k, node, depth + 1);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b;
  cin >> n;
  while (--n)
  {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, -1,0); //getting farthest vertice from root

  maxd = INT_MIN;

  dfs(temp,-1, 0);

  cout << maxd << "\n";

  return 0;
}