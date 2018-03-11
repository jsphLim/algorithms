#include<bits/stdc++.h>
using namespace std;
int n,cnt = 1;
int vis[50],ans[50]={1};
bool su(int x){
	if(x==n) return (ans[n]+ans[n-1]+ans[1])%7;
	if(x==1) return (ans[1]+ans[n]+ans[2])%7;
	return (ans[x]+ans[x-1]+ans[x+1])%7;
}
void dfs(int x)
{
	if(x == n && su(x))
	{
		cnt++;
	}
	else for(int i=1;i<=n;i++)
		if(!vis[i] && su(i))
		{
			ans[x] = i;
			vis[i] = 1;
			dfs(x+1);
			vis[i] = 0;
		}
}

int main()
{
	while(~scanf("%d",&n))
	{
		cnt=0;
		memset(vis,0,sizeof(vis));
		dfs(1);
		cout<<cnt<<endl;
	}
}

