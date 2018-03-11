/*
运动的方向不仅仅是周围的四个点，因为没求最短时间，所以避免提前结束bfs，就四个方向搜到底
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    int x,y,k;//k存拐弯数
};
int t,n,m,x1,x2,y1,y2,k,vis[110][110];
char map[110][110];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void bfs(node vs,node vd)
{
    int flag=0;
    queue<node>q;
    node vn,vw;
    vn.x=vs.x;
    vn.y=vs.y;
    vn.k=-1;//-1,不是0；
    vis[vs.x][vs.y]=1;
    q.push(vn);
    while(!q.empty())
    {
        vn=q.front();
        q.pop();
        if(vn.x==vd.x&&vn.y==vd.y&&vn.k<=k)
        {
            flag=1;break;
        }

        vw.k=vn.k+1;//因为前面搜完了一个方向，就肯定会拐弯，所以要+1，也因此起点的k初始化为-1;

        {
            int i;
            for(i=0;i<4;i++)
            {
                int a=vn.x+dx[i];
                int b=vn.y+dy[i];
                while(a>=0&&a<n&&b>=0&&b<m&&map[a][b]!='*')//搜完一个方向
                {
                    if(!vis[a][b])
                    {
                        vis[a][b]=1;
                        vw.x=a;vw.y=b;
                        q.push(vw);
                    }
                    a+=dx[i];
                    b+=dy[i];
                }
            }
        }
    }
    printf("%s\n",flag?"yes":"no");
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        node vs,vd;
        int i;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);//注意他说的行列和常规的想法不一样，免得自己搞混，所以我先输入的y。
        vs.x=x1-1;vs.y=y1-1;
        vd.x=x2-1;vd.y=y2-1;
        bfs(vs,vd);
    }
    return 0;
}

