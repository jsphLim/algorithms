#include<stdio.h>
#include<math.h>
int arr[10005]={0};
int main()
{
	int t,n,flag,k=0,m=1;
	int i,j;
	scanf("%d",&t);
	arr[0]=4;
    for(i=3;i<10005;i++)
	{	for(j=2;j<i;j++)
		{
			if(i%j==0) 
			{flag=0;
			break;
			}
			else
				flag=1;
		}
	if(flag)
	{
		arr[m]=(i*i);
		m++;
	}
	
	}
	while(t--)
	{
         scanf("%d",&n);
		 for(i=0;i<10005;i++)
		 {
	           if((arr[i+1]-n)>=(n-arr[i]))
				k=arr[i];
				else
				k=arr[i+1];
			   if((arr[i+1]-n)>=0&&(n-arr[i])>=0) break;
		 }
		 printf("%d\n",k);
		 k=0;
	}
	return 0;
}
