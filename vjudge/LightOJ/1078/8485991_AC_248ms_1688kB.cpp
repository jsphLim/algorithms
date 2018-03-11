#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
	long long t,a,b,n,res;
	cin>>t;
	int kcase=1;
	while(t--){
		scanf("%lld%lld",&a,&b);
		n=b%a;
		res=1;
		while(n){
			n=(10*n+b)%a;
			res++;
		}
		printf("Case %d: %lld\n",kcase++,res);
	}
}