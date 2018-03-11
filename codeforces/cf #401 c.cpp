#include<bits/stdc++.h>
using namespace std;
int x,y,k;
int l,r,flag=0;
int main()
{
	scanf("%d%d",&x,&y);
	int s[x+10][y+10];
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			scanf("%d",&s[i][j]);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&l,&r);
		flag=0;
		for(int j=0;j<y;j++)
		{
			for(int c=l-1;c<r;c++)
			{
				if(c==r-1)
				{
					flag=1;
				}
				if(s[c][j]>s[c+1][j])
					break;
			}
			if(flag==1)
				break;
		}
		if(!flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
