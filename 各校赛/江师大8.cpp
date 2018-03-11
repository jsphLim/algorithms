#include<stdio.h>
int main(){
	int n,t;
	int A,C;
	int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&A,&C);
		for(i=1;C*i<=1e9;i=i*C)
		for(j=1;j<1e9;j++){
			if(i%j==0&&i%A==0&&i/j==i/A){
				if(j!=n){
				n=j;
				printf("%d\n",n);
				} 
			} 
		}
	}
}
