#include<stdio.h>
int arr[1000000];
int main()
{
	int n,i,j;
	int t=1,m=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	    for(i=0;i<n-1;i++){
	    	for(j=i+1;j<n;j++){
	    		if(arr[i]==arr[j]){
	    			t++;
				}	
			}
			if(t>=(n+1)/2)
			{
				printf("%d\n",arr[m]);
				break;
			}
			m++;
			t=1;
		}
		
		t=1;
		m=0;
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
 } 
