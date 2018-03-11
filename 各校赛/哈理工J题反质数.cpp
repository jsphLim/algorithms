#include<stdio.h>
int arr[1005];
int sushu(int n)
{
	int i,z=1;
	for (i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			z = 0;
			break;
		}
	}
	return z;
}
    
int f(int n)   
  { 
    int i,r;
	r = 0;
	while(n !=0){i = n %10;
	r = r * 10 + i;n = n /10;}
	return r;
}		
int main()
{
	int t,n;
	int i,j;
	int m=0;
	for(i=10;i<71000;i++){
		if(f(i)!=i){
	    if(sushu(i)){
	    	if(sushu(f(i))){
	    		arr[m]=i;
	    		m++;
			}
		}
	}
		}
		scanf("%d",&t);
		for(i=0;i<t;i++){
			scanf("%d",&n);
			printf("%d\n",arr[n-1]);
		}
	
					
}
    


