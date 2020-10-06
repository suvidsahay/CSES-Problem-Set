#include <bits/stdc++.h>
using namespace std;

const int maxN=2e5+5;
vector<int> adj[maxN];

int height[maxN],ans[maxN],maxi[maxN],secondMaxi[maxN];

void dfs1(int u,int p=-1,int lvl=0){
    for(int v:adj[u]){
        if(v!=p){
            dfs1(v,u,lvl+1);
            height[u]=max(height[u],height[v]+1);
            if(maxi[u]==0 || height[v]>height[maxi[u]]){
                secondMaxi[u]=maxi[u];
                maxi[u]=v;
            }else if(secondMaxi[u]==0 || height[v]>height[secondMaxi[u]]){
                secondMaxi[u]=v;
            }
        }
    }
}

void dfs2(int u,int p=-1){
    for(int v:adj[u]){
        if(v!=p){
            ans[v]=ans[u]+1;
            if(maxi[u]==v){
                if(secondMaxi[u]){
                    ans[v]=max(ans[v],2+height[secondMaxi[u]]);
                }
            }else{
                ans[v]=max(ans[v],2+height[maxi[u]]);
            }
            dfs2(v,u);
        }
    }
    ans[u]=max(ans[u],height[u]);
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
    dfs2(1);
    for(int x=1;x<=n;x++){
        // cout<<height[x]<<" ";
        // cout<<"("<<maxi[x]<<" , "<<secondMaxi[x]<<")\t\t";
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