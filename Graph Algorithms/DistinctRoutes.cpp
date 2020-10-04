#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;
vector<vector<int>> directedAdj;

/**
 * Read about Max Flow here:
 * https://cp-algorithms.com/graph/edmonds_karp.html
 *
 * Idea:  Assign each edge a weight equal to 1, and find max flow from 1 to N.
 *        Weight = 1 ensures that each edge is used at-most once in calculating the flow. 
 *        Once we know max flow, we need to recover the paths from 1 to N.
 *        All the 'Used Edges' will have weight = 0 in 'capacity' vector.
 *        Use this info to recover paths.
 **/

int bfs(int s, int t, vector<int> &parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});
  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(n);
  int new_flow;
  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}

vector<vector<int>> recoverPath(int maxFlow) {
  queue<vector<int>> q;
  while (maxFlow--)
    q.push(vector<int>(1, 0));
  vector<vector<int>> paths;
  while (!q.empty()) {
    vector<int> currentPath = q.front();
    int x = currentPath.back();
    q.pop();
    if (x == n - 1) {
      paths.push_back(currentPath);
      continue;
    }
    for (int v : directedAdj[x]) {
      if (capacity[x][v] == 0) {
        currentPath.push_back(v);
        capacity[x][v] = 1;
        q.push(currentPath);
        break;
      }
    }
  }
  return paths;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  capacity.resize(n, vector<int>(n, 0));
  adj.resize(n);
  directedAdj.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    capacity[x][y] = 1;
    directedAdj[x].push_back(y);
  }
  int maxFlow = maxflow(0, n - 1);
  cout << maxFlow << '\n';
  vector<vector<int>> paths = recoverPath(maxFlow);
  for (auto v : paths) {
    cout << v.size() << '\n';
    for (auto x : v)
      cout << x + 1 << ' ';
    cout << '\n';
  }

  return 0;
}