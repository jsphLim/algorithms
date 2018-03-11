#include<stdio.h>
#include<string.h>
char arr[105];
int main(){
	while(scanf("%s",arr)!=EOF){
		int i,j;
		int max=0;
		int flag;
		int m=0;
		int len=strlen(arr);
		for(i=0;i<len;i++){
			if(arr[i]-'0'>max){
				max=arr[i]-'0';
			}
		}
		for(i=0;i<len;i++){
			printf("%c",arr[i]);
			if(arr[i]-'0'==max) printf("(max)");
		}
		printf("\n");
	}
}
