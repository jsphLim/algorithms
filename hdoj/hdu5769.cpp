#include<stdio.h>
#include<string.h>
char arr[105][105]; 
int main(){
	int n,t,sum=0;
	int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",arr[i]);
		}
		int l1,l2;
		l1=strlen(arr[0]);
		l2=strlen(arr[1]);
		if(l1>l2){
			int t=l1;
			l1=l2;
			l2=t;
		}
		for(i=0;i<l2;i++){
		for(j=0;j<l2;j++){
				if(arr[0][i]==arr[1][j]){
					sum++;
					if(arr[0][i+1]!=arr[1][j+1]) break;
					else i++;
					
				}
				
			}
		}
		printf("%d\n",sum);
		memset(arr,'0',sizeof(arr));
		sum=0;
	}
}
