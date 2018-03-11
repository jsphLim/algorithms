#include<stdio.h>
int main(){
	int n,t,year,i=0;
	scanf("%d",&t);
	while(t--){
	scanf("%d%d",&year,&n);
	if(year%4==0&&year%100!=0||year%400==0) year=year-4;
	while(n){
		year++;
		if(year%4==0&&year%100!=0||year%400==0){
			n--;
		}
	}	
	printf("%d\n",year);
	}
}
