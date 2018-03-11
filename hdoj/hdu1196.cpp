#include<stdio.h>
#include<math.h>
int arr[100];
int i=0;
int to2(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		arr[i++]=num%2;
		to2(num / 2);

	}
}
int main(){
	int n,m;
	int first,last;
	while(scanf("%d",&n),n){
		to2(n);
		for(i=30;;i--){
			if(arr[i]==1&&arr[i+1]!=0){
				printf("%d",1);
				break;
			}
			else{
				if(arr[i]==0) last=i;
				if(arr[i]==1){
					first=i;
					break;
				}
				printf("%d",pow(2,last-first));
			}
		}
	}
}
		
