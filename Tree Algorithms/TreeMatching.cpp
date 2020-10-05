#include <bits/stdc++.h>
using namespace std;

const int maxN=2e5+5;
vector<int> adj[maxN];
 
int take[maxN],not_take[maxN];
 
void dfs(int u,int p=-1){
	for(int v:adj[u]){
		if(v!=p){
			dfs(v,u);
			not_take[u]+=max(not_take[v],take[v]);
			take[u]=max(take[u],1+not_take[v]);
		}
	}
	for(int v:adj[u]){
		if(v!=p){
			take[u]=max(take[u],not_take[u]-max(take[v],not_take[v])+not_take[v]+1);
		}
	}
}
 
void solve(){
	int n;
	cin>>n;
	for(int x=1;x<n;x++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout<<max(take[1],not_take[1])<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}