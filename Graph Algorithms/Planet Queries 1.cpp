#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
    int n,q,x;
    ll k;
    cin>>n>>q;
    int tele[n];

    for(int i=0;i<n;i++)
    cin>>tele[i];

    while(q--)
    {
       
        cin>>x>>k;

        while(k--)
        {
            x = tele[x-1];
        }

        cout<<x<<"\n";
    }

    return 0;
}
