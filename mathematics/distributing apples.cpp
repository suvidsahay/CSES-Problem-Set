
#include <bits/stdc++.h>

#define ll  long long 
#define mod 1000000007
#define maxn 2000001

using namespace std;

ll fact[maxn];
ll inv[maxn];

ll exponentiation(ll n, ll p){
    ll r = 1; 
    while(p > 0){
        if(p & 1){
            r = (r * n) % mod;
            p--;
        }
        else{
            p = p / 2;
            n = (n * n) % mod;
        } 
    }
    return r;
}
void factorial_andinversefactorial(){
	fact[0]=1;
	inv[0]=1;
    for(int i = 1; i < maxn; i++){
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = exponentiation( fact[i], mod - 2 );
    }
}

ll cal_nck(ll n, ll k){
    ll res, r;
    if(n >= k){
        r = ( fact[n] * inv[k] ) % mod;
        res = (r * inv[n - k]) % mod;
        return res;
      }

     return 0; 
}

int main(){
    factorial_andinversefactorial();
    int test = 1;
    while(test--){
         int  n, k , i, m;
         cin >> n >> m;
        k = cal_nck(n + m -1, n - 1);
        cout << k ;  
    }   
}
