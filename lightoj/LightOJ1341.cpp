#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n,m;
	int t,kase=1;
	cin>>t;
	while(t--){
		scanf("%lld%lld",&n,&m);
		int k=sqrt(n);
		int sum=0;
		for(int i=m;i<=k;i++){
			if(n%i==0) sum++;
		}
		printf("Case %d: %d\n",kase++,sum);
	}
}
