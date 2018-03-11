#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
int f[3005];
int prime_len;
int primes[3005];
bool flag[3005];//素数为false，非素数为true
void initPrimes(int n){//在2~n中判断
    memset(flag,0,sizeof(flag));   
    prime_len=1;
    primes[0]=1;
    for(int i=2;i<=n;i++){
        if(!flag[i]) primes[prime_len++]=i;
        for(int j=0;i*primes[j]<= n;j++){
            flag[i*primes[j]]=true;     
            if(i%primes[j]==0)break;
        }
    }
}
int main(){
	int V,m,k;
	initPrimes(3005);
	while(~scanf("%d%d",&V,&m)){
		for(int i=0;i<=V;i++) f[i]=1;
		
		for(int i=0;i<=prime_len&&primes[i]<=V;i++)
			for(int j=primes[i];j<=V;j++){
				f[j]=max(f[j],(f[j-primes[i]]*primes[i]/__gcd(f[j-primes[i]],primes[i])));
			}
			cout<<f[V]%m<<endl;
	}
}
