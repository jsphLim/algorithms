#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 101000
using namespace std;
struct KSD
{
	int v,next;
}e[N<<1];
int head[N],cnt;
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int n;
int sg[N];
void dfs(int x,int p)
{
	int i,v;
	sg[x]=0;
	for(i=head[x];i;i=e[i].next)
	{
		v=e[i].v;
		if(v==p)continue;
		dfs(v,x);
		sg[x]^=(sg[v]+1);
	}
}
int main()
{
	int i,j,T;
	int a,b;
	for(scanf("%d",&T);T--;)
	{
		cnt=1;
		memset(head,0,sizeof(head));
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b),add(b,a);
		}
		dfs(1,0);
		if(sg[1])puts("Alice");
		else puts("Bob");
	}
	return 0;
}
