#include<stdio.h>
#include<math.h>
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int step,mod;
	while(scanf("%d%d",&step,&mod)!=EOF){
		if(gcd(step,mod)==1)  printf("%10d%10d    Good Choice\n\n", step, mod);
		else printf("%10d%10d    Bad Choice\n\n", step, mod);
	}
}
