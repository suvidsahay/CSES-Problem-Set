#include <bits/stdc++.h>

#define ll  long long 
#define mod 1000000007
#define maxn 1000001

using namespace std;
int val[maxn];
int main(){
 int i, j, k, l, n;
 cin >> n;
 int a[n];
 for(i = 0; i < n; i++){
    cin >> a[i];
    val[a[i]]++;
 }
 l = 1;
 for(i = 2; i < maxn; i ++){
 	k  = 0;
 for(j = i; j < maxn;j += i){
      	if(val[j] > 1)
      		l = max(j, l);
     	if( k == 1 && val[j] > 0 ){
      		l = max(l , i);
        } 	
      	if(val[j] > 0 && k == 0){
      		k = 1;
      	}     
 }

}
 cout << l;
}

