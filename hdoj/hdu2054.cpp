#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int cal=0;
		for(int i=1;i<=n;i++){
			if(n%i==0) cal++;
		}
		if(cal%2==1) printf("%d\n",1);
		else printf("%d\n",0);
	}
}
