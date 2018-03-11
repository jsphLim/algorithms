#include<stdio.h>
main()
{
	int i,j,m,n;
	scanf("%d",&n);
	while(n--)
	{
		int a[1000];
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			for(j=i;j<m;j++)
			{
				if(a[i]>a[j])
				{
					int h;
					h=a[i];a[i]=a[j];a[j]=h;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			if(i==0)
			printf("%d",a[i]);
			else
			printf(" %d",a[i]);
		}
		printf("\n");
		
	}
}
