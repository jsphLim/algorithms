
#include<stdio.h>
void main()
{
	int arr[1000000005];
	int b[1000000005];
	int t,n,m;
	int i,sum=0;
	scanf("%d",&t);
	while(t--)
	{
       scanf("%d",&n);
	   for(i=0;i<n;i++)
	   {
		   scanf("%d",&arr[i]);
	   }
       scanf("%d",&m);
	    for(i=0;i<n;i++)
	   {
		   scanf("%d",&b[i]);
	   }
	   for(i=0;i<m;i++)
	   {
           for(i=0;i<b[i];i++)
			   sum=sum+arr[i];
		   printf("%ld\n",sum);
	   }
	   }
}



	
