/**********************
* author:crazy_石头
* Pro:SGU 143
* algorithm:Tree dp
* Time:15ms
* Judge Status:Accepted
***********************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define LL long long
#define rep(i,h,n) for(int i=(h);i<=(n);i++)
#define ms(a,b) memset((a),(b),sizeof(a))
#define INF 1<<29

const int maxn=16000+5;

struct Edge
{
    int to,next;
}edge[maxn<<1];

int head[maxn],cnt;
bool vis[maxn];
int f[maxn],dp[maxn];//dp[i]数组记录以i出发dfs一个连通块所能得到的权值；

inline void init()
{
    ms(head,-1),cnt=0;
}

inline void addedge(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

inline void add(int u,int v)
{
    addedge(u,v);
    addedge(v,u);
}

inline int dfs(int u)
{
    vis[u]=1;
    dp[u]=f[u];
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            dfs(v);
            vis[v]=1;
            if(dp[v]>0)
            dp[u]+=dp[v];//先dfs，再从底向上依次更新最优值；
        }
    }
    return dp[u];
}

int main()
{
    int n;
    scanf("%d",&n);
    rep(i,1,n)
        scanf("%d",&f[i]);
    init();
    rep(i,1,n-1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    ms(vis,0);
    dfs(1);
    int ans=-INF;
    rep(i,1,n)
    ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
