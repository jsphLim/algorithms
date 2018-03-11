#include <stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    char a[1005][20];
	int b[1005];
	while(scanf("%d",&n)&&n!=0)
	{
		b[0]=0;
		scanf("%s",a[0]);
		for(i=1;i<n;i++)
		{   b[i]=0;
			scanf("%s",a[i]);
        for(j=0;j<i;j++)
		{
			if(strcmp(a[i],a[j])==0)
				b[i]++;
		}
		}
        int max=0,m=0;
		for(i=1;i<n;i++)
		{
			if(b[i]>max)
			{
				max=b[i];
				m=i;
			}
		}
        printf("%s\n",a[m]);
	}
return 0;
}
/*
#include<stdio.h>
#include<string.h>
main()
{
	int i,j,k,n,num[1000],max,t;
	char color[1000][16];
	while(scanf("%d",&n)&&n!=0)
	{
		
			num[0]=0;
			scanf("%s",color[0]);
			for(i=1;i<n;i++)
			{
				num[i]=0;
				scanf("%s",color[i]);
				for(j=0;j<=i-1;j++)
				{
					if(strcmp(color[i],color[j])==0)
						num[i]++;
				}
			}
			max=0;
			t=0;
			for(i=1;i<n;i++)
			{
				if(max<num[i])
				{
					max=num[i];
				t=i;
				}
			}
			printf("%s\n",color[t]);
		
	}
}
*/