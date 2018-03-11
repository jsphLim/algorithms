#include <cstdio>
#include <cstring>

const int p=1000000007;

char c[1200000];
int i,n,r,s,t;

int main()
{
	gets(c+1);
	n=strlen(c+1);
	r=1;
	for (i=1;i<=n;i++)
		if (c[i]=='a')
			r=(r+r)%p;
		else
			s=(s+r-1)%p;
	printf("%d",s);
	return 0;
}