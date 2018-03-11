#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
char a[20][20][20];
int vis[20][20][20];
int n;
char ch[10];
int ans;
int sx,sy,sz,ex,ey,ez;
int dir[6][3]= {0,1,0,1,0,0,-1,0,0,0,-1,0, 0,0,1,0,0,-1};             
struct node
{
    int x,y,z,t;
};
int bfs()
{
    node now,next;
    queue<node>q;
    memset(vis,0,sizeof(vis));
    vis[sz][sx][sy]=1;
    now.x=sx;
    now.y=sy;
    now.z=sz;
    now.t=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==ex&&now.y==ey&&now.z==ez)
        {
            return now.t;
        }
        for(int i=0; i<6; i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            next.z=now.z+dir[i][2];
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<n&&next.z>=0&&next.z<=n&&vis[next.z][next.x][next.y]==0&&a[next.z][next.x][next.y]!='X')
            {
                vis[next.z][next.x][next.y]=1;
                next.t=now.t+1;
                q.push(next);
            }
        }
    }
    return -99999;
}

int main()
{
    while(~scanf("%s%d",ch,&n))
    {
        getchar();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                    scanf("%c",&a[i][j][k]);
                getchar();
            }

        }
        scanf("%d%d%d",&sy,&sx,&sz);
       scanf("%d%d%d",&ey,&ex,&ez);
        cin>>ch;
        ans=bfs();
        if(ans!=-99999)
            cout<<n<<" "<<ans<<endl;
        else
            cout<<"NO ROUTE"<<endl;
    }
    return 0;
}

