#include<stdio.h>
#include<string.h>
char arr[500];
char brr[500];
int a[500][500]={{0,0}};
int main(){
	int i,j;
	int l1,l2,sum=0;
	while(scanf("%s%s",arr,brr)!=EOF){
		l1=strlen(arr);
		l2=strlen(brr);
		for(i=1;i<=l1;i++){
			for(j=1;j<=l2;j++){
				if(arr[i-1]==brr[j-1]){
					a[i][j]=a[i-1][j-1]+1;
				}
				else{
					if(a[i-1][j]>=a[i][j-1]) a[i][j]=a[i-1][j];
					else a[i][j]=a[i][j-1];
				}
			}
		}
		
		printf("%d\n",a[l1][l2]);
	}
}
