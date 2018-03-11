#include<stdio.h>
#include<math.h>
int main()
{
	int n,t,sum=0,i;
	int a[100];
	while(scanf("%d",&n)&&n!=0)
	{
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]>0)
				sum=sum+(a[i]-a[i-1])*6;
			else
				sum=sum+(a[i-1]-a[i])*4;
			
		}sum=sum+n*5;
		printf("%d\n",sum);
		sum=0;
	}
	return 0;
}