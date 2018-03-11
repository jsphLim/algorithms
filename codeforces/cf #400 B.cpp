#include<cstdio>
bool b[100002];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	if(n<3)
	{
		puts("1");
		while(n--)printf("1 ");
		return 0;
	}
	n++,puts("2");
	for(i=2;i<=n;i++)
		if(b[i])
			printf("2 ");
		else{
			printf("1 ");
			for(j=2;i*j<=n;j++)
				b[i*j]=true;
		}
}
