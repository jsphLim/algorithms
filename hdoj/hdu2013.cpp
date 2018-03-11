#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		n--;
		while(n--)
			sum=(sum+1)*2;
		printf("%d\n",sum);
	}
}
