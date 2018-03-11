#include<stdio.h>

int go(int n)
{
	int sum=0;
	while(1)
	{
		sum++;
		if(n==1)
		{
			return sum;
		}
		if(n%2==1)
		{
			n=3*n+1;
		}
		else
		{
			n/=2;
		}
	}
}
 
 
 int main(){
 	int m,n;
 	int i,j;
 	int max=0,t;
 	int a,b;
 	while(scanf("%d%d",&m,&n)!=EOF){
 		a=m;
 		b=n;
 		printf("%d %d",a,b);
 		if(a>b){
 			int temp=a;
 			a=b;
 			b=temp;
		 }
 		for(i=a;i<=b;i++){
 		     t=go(i);
 			if(t>max) max=t;
		 }	
		 printf(" %d\n",max);
		 max=0;
	 }
	
 }
