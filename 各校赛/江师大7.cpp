#include<stdio.h>
int arr[100][100];
int main(){
	int a;
	char b,c;
	int k=0;int i,j;
	int n=1;
	while(n){
		scanf("%d %c %c",&a,&c,&b);
		n=a;
	for(i=0;i<(a+1)/2;i++)
	for(j=0;j<a;j++){
		if(i==0||i==j||a-i-1==j){
			arr[i][j]=b;
		}
		else if((j<(a+1)/2&&i<j)||(j>=(a+1)/2&&i<a-j-1)) {
		arr[i][j]=c;
		}	
	}
	printf("Case %d:\n",++k);
	for(i=0;i<(a+1)/2;i++){
	for(j=0;j<a;j++)
	printf("%c",arr[i][j]);
	printf("\n");
}
printf("\n");
}
} 
