#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
const int maxn=200001;
#define pb  push_back
vector<int>v[maxn];
int max_depth;
int d[maxn];
void dfs(int node,int par)
{
	int mx1=0;
	int mx2=0;
	for(int child:v[node])
	{
		if(child!=par)
		{
			
			dfs(child,node);

			if(d[child]+1 >= mx1)
			{
                 int temp=mx1;
                 mx1=d[child]+1;
                 mx2=temp;

		   }
		    else if(mx2<= d[child]+1)
		    {

		    	mx2=d[child]+1;

		    }

		}
	}

	max_depth=max(max_depth,mx1+mx2);
	d[node]=mx1;
}
int main()
{

   int i,j,k,n;
   cin>>n;
   for(i=1;i<n;i++)
   {
   	cin>>j>>k;
   	v[j].pb(k);

   	v[k].pb(j);

   }
   
   dfs(1,0);
   cout<<max_depth;

	
}
