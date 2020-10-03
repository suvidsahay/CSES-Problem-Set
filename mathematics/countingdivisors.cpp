
#include <bits/stdc++.h>

#define ll  long long 
#define mod 1000000007
#define maxn 1000001

using namespace std;

int fact[maxn];
void num_offactors()
{
  
  ll i,j;
  for(i = 1;i < maxn; i++)
  {

      for(j=i;j<maxn;j = j + i)
       {

        fact[j]+= 1;
       }
   }
   
return;
}
int main()
{
  num_offactors();
 
  int query,n;

  cin>>query;

  while(query--)
  {
    cin>>n;

    cout<<fact[n]<<"\n";
  }

}

