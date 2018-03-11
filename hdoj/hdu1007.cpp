#include<stdio.h>
__int64 arr[25]={0,0,1,2};
__int64 fact(__int64 n)
{
   __int64 i,s=1;
   for(i=2;i<=n;i++)
	   s=s*i;
   return s;
}
int main()
{
	__int64 n,t,m,a,i;
	scanf("%I64d",&t);
		while(t--)
		{
			scanf("%I64d %I64d",&m,&n);
            a=fact(m)/(fact(n)*fact(m-n));
            for(i=4;i<21;i++)
			{
            arr[i]=(i-1)*(arr[i-1]+arr[i-2]);
			}
			printf("%I64d\n",arr[n]*a);
		}
}
