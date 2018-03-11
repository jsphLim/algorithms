#include<bits/stdc++.h>
using namespace std;
long long fib[100000];
long long fibsum[100000];
	int n,m,k;
int main(){
	fib[1]=1;
	fib[2]=1;
	memset(fibsum,0,sizeof(fibsum));
	for(int i=3;i<=100000;i++) fib[i]=fib[i-1]+fib[i-2];
	for(int i=1;i<=100000;i++) fibsum[i]=fibsum[i-1]+fib[i];
	

	while(~scanf("%d%d%d",&n,&m,&k)){
		cout<<__gcd(fibsum[n]+1,fibsum[m]+1)%k<<endl;
	}
}
