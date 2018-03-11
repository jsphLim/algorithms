#include<stdio.h>
void main()
{

     int n,i,k=0;
	while(scanf("%d",&n)!=-1&&n!=-1)
	{
		while(n)
		{
			k=k+n%2;
			i++;
			n=n/2;
		}
            printf("%d\n",k);
			k=0;
	}

}
