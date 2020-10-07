#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int maxN=2e5+5;
vector<int> adj[maxN];
ll subSum[maxN],ans[maxN];
int cnt[maxN];

void dfs1(int u,int p=-1){
    cnt[u]=1;
    for(int v:adj[u]){
        if(v!=p){
            dfs1(v,u);
            cnt[u]+=cnt[v];
            subSum[u]+=subSum[v]+cnt[v];
        }
    }
}

void dfs2(int u,int p=-1){
    for(int v:adj[u]){
        if(v!=p){
            int tmp_cnt_v=cnt[v];
            ll tmp_subSum_v=subSum[v];
            int tmp_cnt_u=cnt[u];
            ll tmp_subSum_u=subSum[u];
            
            subSum[u]-=(subSum[v]+cnt[v]);
            cnt[u]-=cnt[v];
            subSum[v]+=subSum[u]+cnt[u];
            cnt[v]+=cnt[u];
            ans[v]=subSum[v];

            dfs2(v,u);            

            cnt[v]=tmp_cnt_v;
            subSum[v]=tmp_subSum_v;
            cnt[u]=tmp_cnt_u;
            subSum[u]=tmp_subSum_u;
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
    dfs1(1);
    ans[1]=subSum[1];
    dfs2(1);
    for(int x=1;x<=n;x++){
        cout<<ans[x]<<" ";
    }cout<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}