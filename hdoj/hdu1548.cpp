#include<iostream>
#include<string.h>
using namespace std;
#define INF 999999
int mp[500][500];
int dis[500],vis[500];
int n;
void Dijkstra(int v)
{ 
    int i,j,pos,minn;
    memset(vis,0,sizeof(vis));   
    for(i=1;i<=n;i++)
        dis[i]=mp[v][i];
    vis[v]=1; 
    dis[v]=0;
    for(j=1;j<n;j++) 
    { 
        pos=0; 
        minn=100000000; 
        for(i=1;i<=n;i++) 
            if(dis[i]<minn&&vis[i]==0)
            { 
                pos=i;
                minn=dis[i];
            }
            vis[pos]=1; 
            for(i=1;i<=n;i++)
                if(dis[i]>dis[pos]+mp[pos][i]) 
                    dis[i]=dis[pos]+mp[pos][i]; 
    } 
} 
int main()
{
    int st,en,i,j;
    int a[500];
    while(cin>>n,n)
    {
        scanf("%d%d",&st,&en);
        memset(mp,INF,sizeof(mp));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i+a[i]<=n)
             mp[i][i+a[i]]=1;
            if(i-a[i]>=1)
             mp[i][i-a[i]]=1;
        }
        Dijkstra(st);
        if(dis[en]>INF)
            cout<<-1<<endl;
        else
        cout<<dis[en]<<endl;
    }
    return 0;
}
