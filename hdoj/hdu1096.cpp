#include<stdio.h>
#include<string.h>
char arr[1000],brr[1000];
int max(int x,int y){
	return x>y?x:y;
}
int main()
{   int n,i,j,t,sum=0;
	while(~scanf("%s %s",arr,brr)){
	
	int l1=strlen(arr);
	int l2=strlen(brr);
	int l=max(l1,l2);
	for(i=0;i<l-1;i++){
		for(j=i+1;j<l;j++){
			if(arr[i]==arr[j]) arr[j]='.';
			if(brr[i]==brr[j]) brr[j]='.';
		}
	}
	    for(i=0;i<l;i++)
		for(j=0;j<l;j++){
			if(arr[i]!='.'&&arr[i]!='0'){
			if(arr[i]==brr[j]){
				sum++;
				arr[i]='0';
				brr[j]='0';
			}
		}
		}
	printf("%d\n",sum);
	sum=0;
}
}
