#include<stdio.h>
int main(){
	int depth,up,down,sum=0,n=0;
	while(scanf("%d%d%d",&depth,&up,&down)&&depth&&up&&down){
	while(sum<depth){
		sum=sum+up-down;
		if(sum+down>=depth) break;
		n=n+2;
	}
	n=n+1;
	printf("%d\n",n);
	n=0;
	sum=0;
}
}
