#include<stdio.h>
int main(){
	int n,m=0;
	int i,j;
	int year,month,day;
	scanf("%d",&n);
	while(n--){
		scanf("%d-%d%-%d",&year,&month,&day);
		if((year%4==0&&year%100!=0||year%400==0)&&(month<2||(month==2&&day<29))) m++;
		for(i=year+1;i<=year+17;i++){
			if(i%4==0&&i%100!=0||i%40==0) m++;
		}
		if(((year+18)%4==0&&(year+18)%100!=0||(year+18)%400==0)&&(month>2||(month==2&&day==29))) m++;
		if((year+18)%4==0&&(year+18)%100!=0||(year+18)%400==0&&month==2&&day==29)
		printf("%d",-1);
		else
		printf("%d\n",18*365+m);
		m=0;
	}
} 
