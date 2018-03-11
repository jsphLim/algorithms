#include <bits/stdc++.h>
using namespace std;  
const int inf = 999999999;  
int mp[1005][1005];  
int vis[1005],d[1005],p[1005];  
int n,m,flag;  
void Dijkstra(int x)  
{  
    int i,j,minn,pos;  
    memset(vis,0,sizeof(vis));  
    for(i = 0; i<=n; i++)  
        d[i] = inf;  
    d[x] = 0;  
    for(i = 1; i<=n; i++)  
    {  
        minn = inf;  
        for(j = 1; j<=n; j++)  
        {  
            if(d[j]<minn && !vis[j])  
                minn = d[pos = j];  
        }  
        vis[pos] = 1;  
        for(j = 1; j<=n; j++)  
            if(d[pos]+mp[pos][j]<d[j])  
            {  
                d[j] = d[pos]+mp[pos][j];  
                if(flag)
                    p[j] = pos;  
            }  
    }  
}  
  
int main()  
{  
    int i,j,x,y,w;  
    while(~scanf("%d%d",&n,&m))  
    {  
        for(i = 0; i<=n; i++)  
        {  
            for(j = 0; j<=n; j++)  
                mp[i][j] = inf;  
            mp[i][i] = 0;  
        }  
        while(m--)  
        {  
            scanf("%d%d%d",&x,&y,&w);  
            if(w<mp[x][y])  
                mp[x][y] = mp[y][x] = w;  
        }  
        memset(p,0,sizeof(p));  
        flag=1;
        Dijkstra(1);  
        int ans = d[n]; 
		flag=0; 
        for(i = n; i!=1; i=p[i])  
        {  
            int tem = mp[i][p[i]];  
            mp[i][p[i]] = mp[p[i]][i] = inf;  
            Dijkstra(1);  
            ans = max(ans,d[n]);  
            mp[i][p[i]] = mp[p[i]][i] = tem;  
        }  
        printf("%d\n",ans);  
    }  
  
    return 0;  
}  


