//��Ҫ��״̬ת��ʽ,DP
//GetBrain(parent, Soldier) = max{ GetBrain(parent, Soldier-send) + GetBrain(son, send) } 
//1<=send<=Soldier-cost(parent),son��parent�Ķ��ӽڵ� }
//Gain[i][j]��ʾ(i,j,Gain[i][j])=j��ʿ����i�ڵ��ϻ����Gain[i][j]����
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

const int N = 110;
int n,SodierSum,Gain[N][N],bug[N],brain[N];

vector<int> g[N];
/*�ڽӱ�,g[i][0]��ŵ�����i�ڽӵĽ����Ŀ,��1��ʼ��Ž��
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

	//�ڵ���ۣ���Ҫ�ɳ���ʿ������������ȡ��
    int cost=(bug[root]+19)/20;
	//���ʿ���޷�����bugs����Ȼ�޷���ñ���
    if( SodierSum < cost ) 
		return ;
	//��cost������Ϊsodier����������>=cost���ܻ�ñ���
	//ֻҪʿ����>=cost,���񱦲���һ���ģ�����brain[root]
    for(int i=cost;i<=SodierSum;++i)    
        Gain[root][i]=brain[root];

    for(int i=0;i<size;++i)
    {
        int son=g[root][i];//���ڽӵ�,�ö�ά�����ͼ,ʵ����������ʽ�洢
        if(visited[son])
			continue;
        dfs(son); //dfs+dp˼��
        for(int sodier=SodierSum;sodier>=cost;--sodier)//����sodier��
        {
            for(int send=1;send<=sodier-cost;send++)//�ɳ�ȥ��ʿ�����sodier-cost,��Ϊ����Ҫ����cost���ڸ��ڵ�
				//״̬ת��,����
				if( sodier - send >= cost) //���ص�ʿ��Ӧ��>=cost,��ĿҪ��
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
        if(SodierSum==0)//û���˾Ͳ����ܻ��brain
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

������
�������ı���
����Ϊm
����Ϊbugs�������� ��ֵΪbrain������
����ÿ����Ѩ��ѡ���߲�ѡ
�����ѨҪѡ�����ҽ������ױ�ѡ
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
        for(int j=m; j>=t; --j)//����Ӻ���ǰ�ƣ����� ��ת�Ʒ��̿��Կ�����ǰ���״̬�����ں����״̬������Ҫ��������״̬
            for(int k=1; k+j<=m; ++k)//���п��ܵ������Ҫö�٣�Ȼ��������ֵ
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
