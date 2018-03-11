#include<stdio.h>
int arr[105];
int main(){
	int n;
	int i;
	int sum=0;
	while(scanf("%d",&n)&&n){
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++){
			sum=sum+(arr[i]/100+(arr[i]%100)/50+(((arr[i]%100))%50)/10+((((arr[i]%100))%50)%10)/5+(((((arr[i]%100))%50)%10)%5)/2+((((((arr[i]%100))%50)%10)%5)%2));
		}
		printf("%d",sum);
		sum=0;
	}
	return 0;
}
