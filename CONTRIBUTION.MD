#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
const int maxn=2000002;
#define mod 1000000007
#define pb  push_back
#define pie 3.14159265358
vector<int>v[21];
ll dp[21][(1<<20)];
ll n;
ll solve(ll fl,ll mask)
{

  ll ans=0;
  if(mask==(1<<n)-1){
   //ans++;
    return 1;
  }
  if(fl==n)
    return 0;
  if(dp[fl][mask]!=-1)
    return dp[fl][mask];
 
 for(auto it:v[fl])
 {
  if((mask&(1<<(it-1)))==0)
  ans=(ans+solve(it,mask|(1<<(it-1))))%mod;
 }
  dp[fl][mask]=ans;

  return ans;
 
}
int main()
{
 
 int t;
 ll i,j,k,l=0,m,s1=0,pre=-1;
 cin>>n>>m;
  for(i=1;i<=m;i++)
  {
    cin>>j>>k;
    v[j].pb(k);
  }
  memset(dp,-1,sizeof(dp));
  j=1;
  cout<<solve(1,1);
}