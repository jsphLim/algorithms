#include<stdio.h>
int arr[1000][1]={0};
int main(){
	int t,m,p;
	 int i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	for(i=1;i<1000;i++){
		p=i;
		for(j=0;j<t;j++){
			if(i%arr[j][0]==arr[j][1]){
				m=1;
			}
			else{
				m=0;
				break;
			}
		}
		if(m){
			printf("%d",p);
			break;
		}
	}
	
	
	
	

	
}
