//重要的状态转换式,DP
//GetBrain(parent, Soldier) = max{ GetBrain(parent, Soldier-send) + GetBrain(son, send) } 
//1<=send<=Soldier-cost(parent),son是parent的儿子节点 }
//Gain[i][j]表示(i,j,Gain[i][j])=j个士兵在i节点上获得了Gain[i][j]宝藏
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

const int N = 110;
int n,SodierSum,Gain[N][N],bug[N],brain[N];

vector<int> g[N];
/*邻接表,g[i][0]存放的是与i邻接的结点数目,从1开始存放结点
2 2-> 5
2 1-> 5-> 3-> 4
2 2-> 4
3 2-> 5-> 3
3 4-> 1-> 2 
*/
bool visited[N];

void init()
{
    memset(visited,false,sizeof(visited));
    memset(Gain,0,sizeof(Gain));
    for(int i=0;i<=n;++i)
        g[i].clear();
}
void dfs(int root)
{
    visited[root]=true;
    int size=g[root].size();

	//节点代价，需要派出的士兵数量，向上取整
    int cost=(bug[root]+19)/20;
	//如果士兵无法击败bugs，当然无法获得宝藏
    if( SodierSum < cost ) 
		return ;
	//从cost数起，因为sodier的数量必须>=cost才能获得宝藏
	//只要士兵数>=cost,所获宝藏是一样的，都是brain[root]
    for(int i=cost;i<=SodierSum;++i)    
        Gain[root][i]=brain[root];

    for(int i=0;i<size;++i)
    {
        int son=g[root][i];//找邻接点,用二维数组存图,实际上类似链式存储
        if(visited[son])
			continue;
        dfs(son); //dfs+dp思想
        for(int sodier=SodierSum;sodier>=cost;--sodier)//根节sodier数
        {
            for(int send=1;send<=sodier-cost;send++)//派出去的士兵最多sodier-cost,因为至少要留下cost人在父节点
				//状态转移,核心
				if( sodier - send >= cost) //留守的士兵应该>=cost,题目要求．
					Gain[root][sodier]=max(Gain[root][sodier],Gain[root][sodier-send]+Gain[son][send]);
        }
    }
}
int main()
{
    int x,y;
    while(scanf("%d %d",&n,&SodierSum)==2)
    {
        if(n==-1 && SodierSum==-1)
            break;
        for(int i=1;i<=n;++i)
            scanf("%d %d",&bug[i],&brain[i]);
        init();
        for(int root=1;root<n;root++)
        {
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(SodierSum==0)//没有人就不可能获得brain
        {
            printf("0\n");
            continue;
        }
		else
		{
			dfs(1);
			cout << Gain[1][SodierSum] << endl;
		}
       
    }
    return 0;
}
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;
typedef long long LL;                   
const int INF = 1<<30;
const int N = 100+10;
struct Cave
{
    int bugs,brain;
}cave[N];
int dp[N][N];
struct Edge
{
    int v,next;
}g[N<<1];
int head[N],e;

背包？
有依赖的背包
容量为m
费用为bugs的数量， 价值为brain的数量
对于每个洞穴，选或者不选
这个洞穴要选，当且仅当父亲被选
bool vis[N];
int m;
void dfs(int u, int fa)
{
    vis[u] = true;
    int t = (cave[u].bugs+19)/20;
    for(int i=t; i<=m; ++i)
        dp[u][i] = cave[u].brain;
    for(int i=head[u]; i!=-1; i=g[i].next)
    {
        int v = g[i].v;
        if(vis[v]) continue;
        dfs(v,u);
        for(int j=m; j>=t; --j)//必须从后往前推？？？ 由转移方程可以看出，前面的状态依赖于后面的状态，所以要求出后面的状态
            for(int k=1; k+j<=m; ++k)//所有可能的情况都要枚举，然后求出最大值
                dp[u][j+k] = max(dp[u][j+k],dp[u][j]+dp[v][k]);
        
        
    }
}
void init(int n)
{
    for(e=0; e<=n; ++e)
    {
        head[e] = -1;
        vis[e] = false;
    }
    e = 0;
}
void addEdge(int u, int v)
{
    g[e].v = v;
    g[e].next = head[u];
    head[u] = e++;
}
int main()
{
    int n,i,u,v;
    while(scanf("%d%d",&n,&m),n!=-1)
    {
        init(n);
        for(i=1; i<=n; ++i)
            scanf("%d%d",&cave[i].bugs,&cave[i].brain);
        for(i=1; i<n; ++i)
        {
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        if(m==0)
        {
            puts("0");
            continue;
        }    
        memset(dp,0,sizeof(dp));
        dfs(1,-1);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}*/
