/*#include<stdio.h>
#include<math.h>
int main(){
	int n,i,m;
	double t;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(i=2;i<=m;i++){
			t=t+log10(1.0*i);
		}
		int temp; 
		temp=(int)t+1;
		printf("%d\n",temp);
		t=0;
	}
}*/

#include<stdio.h>
#include<math.h>
#define pi 3.14159265359
#define e 2.718281828459
int main(){
	int n,i,m;
	double t;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		int temp;
		if(m==0||m==1) printf("%d",1);
		else{
		temp=log10(2.0*pi*m)/2.0+1.0*m*log10(1.0*m/e);
		int ans=(int)temp+1;
		printf("%d\n",ans);
		t=0;
	}
	}
}
