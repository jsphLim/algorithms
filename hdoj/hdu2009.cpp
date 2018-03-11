#include<stdio.h>
#include<math.h>
int main(){
	int m,n;
	int flag=0;
	int i;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n>m){
			int t=n;
			n=m;
			m=t;
		}
		for(i=n;i<=m;i++){
			if(i==pow(i/100,3)+pow(i%100/10,3)+pow(i%100%10,3)){
				if(i==m) printf("%d",i);
				else  printf("%d ",i);
					flag=1;
			}
	
		}
			if(!flag) printf("no\n");
		flag=0;
	}
		return 0;
}

