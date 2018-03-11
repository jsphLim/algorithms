#include<stdio.h>
int main(){
	int n,m;
    float a,b;
	float sum=0,sum1=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		while(n--){
			for(int i=0;i<m;i++){
				scanf("%d",&a);
				sum=sum+a;
			}
			printf("%f",sum/5);
			sum=0;
			sum1=0;
		}
	}
	
}
