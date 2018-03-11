//µÚ¼¸Ìì£¿
#include<stdio.h>
#include<math.h>
int arr[10000];
int main(){
	int i,sum=0,sum2=0;
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m>n){
			int t=m;
			m=n;
			n=t;
		}
		for(i=m;i<=n;i++){
		if(i%2==0){
			sum2=sum2+pow(i,2);
		}
		else{
			sum=sum+pow(i,3);
		}
	}
	printf("%d %d\n",sum2,sum);
	sum=0;
	sum2=0;
	}
}
