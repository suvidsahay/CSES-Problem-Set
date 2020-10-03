#include <bits/stdc++.h>

#define ll  long long
#define ull unsigned long long  
#define mod 1000000007

using namespace std;

  ll power(ll n,ll p,ll mo)
  {

    ll r=1; 
    while(p>0)
    {

      if(p&1)
      {
          r=(r * n)%mo;

          p--;
       }
      else
      {
       p=p/2;

       n=(n * n)%mo;

       }
      
     }

    return r;
 
   }

  int main(){

       int t;

       cin>>t;

       while(t--)
      {
        ll a,b,r,res,c;

        cin>>a>>b>>c;

         r=power(b,c,mod-1);

         res=power(a,r,mod);

        cout<<res<<"\n";

       }

  }
