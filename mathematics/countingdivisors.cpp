
#include <bits/stdc++.h>

#define ll  long long 
#define mod 1000000007
#define maxn 1000001

using namespace std;

int fact[maxn];
void sieve()
{
  
  ll i,j;
  for(i=1;i<maxn;i++)
  {

    for(j=i;j<maxn;j=j+i)
    {
        fact[j]++;

    }

  }
   
return;
}
int main()
{
  sieve();
 
  int query,n;

  cin>>query;

  while(query--)
  {
    cin>>n;
    
    cout<<fact[n]<<"\n";
  }

}
