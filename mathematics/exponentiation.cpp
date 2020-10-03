#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define mod 1000000007
  ll power(ll  n,ll p,ll mo)
  {
    ll r=1;
    while(p>0)
    {

      if(p&1)
      {
          r=(r*n)%mo;
          p--;
      }
     p=p/2;

     n=(n*n)%mo;


    }
    return r;
  
  }
  int main(){
       int t;
       cin>>t;
       while(t--)
       {


        ll a,b,c;

        cin>>a>>b;

        ll r=power(b,1,mod-1);

        cout<<power(a,r,mod)<<"\n";

       }
  }
