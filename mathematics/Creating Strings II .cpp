
#include <bits/stdc++.h>

#define ll  long long 
#define mod 1000000007
#define maxn 1000001

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

int main(){
    factorial_andinversefactorial();
    int test = 1;
    while(test--){
        string s;
        cin >> s;
        int alpha[26] = {};
        int  n, k , i, j;
        n=s.size();
        for(i = 0; i < n ; i++){
            alpha[s[i] - 'a']++;
        }
        k = fact[n];
        for( i = 0; i < 26 ; i++){
            k = (k * inv[alpha[i]]) %mod;
        }
        cout << k ;  
    }   
}
