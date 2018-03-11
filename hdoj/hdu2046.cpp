#include<stdio.h>
long long int arr[100]={1,1,2};
int main(){
	int n,i,j;
	for(i=3;i<=60;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",arr[n]);
	}
}
