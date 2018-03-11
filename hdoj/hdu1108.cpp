#include<stdio.h>
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",m*n/gcd(m,n));
	}
}
