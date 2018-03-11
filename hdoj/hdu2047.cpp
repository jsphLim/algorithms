
# include <stdio.h>
int main ()
{
	int n=0,i=0;
	__int64 a[60]={0,3,8};
	for(i=3;i<=51;i++)
	{
		a[i]=2*(a[i-1]+a[i-2]);
	}
	while (scanf ("%d",&n)!=EOF)
		printf ("%I64d\n",a[n]);
	return 0;
 }
