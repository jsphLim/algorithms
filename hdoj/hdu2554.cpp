#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
const int inf = 1<<30;  
const int MAX=1200;
int T,S,D,n;  
int map[MAX][MAX];  
int vis[MAX],cast[MAX];  
int s[MAX],e[MAX];  
  
void Dijkstra(int s)  
{  
    int i,j,minn,pos;  
    memset(vis,0,sizeof(vis));  
    vis[1] = 1;  
    for(i = 1; i<=n; i++)  
        cast[i] = map[1][i];  
    for(i = 1; i<=n; i++)  
    {  
        minn = inf;  
        for(j = 1; j<=n; j++)  
        {  
            if(cast[j]<minn && !vis[j])  
            {  
                pos = j;  
                minn = cast[j];  
            }  
        }  
        vis[pos] = 1;  
        for(j = 1; j<=n; j++)  
        {  
            if(cast[pos]+map[pos][j]<cast[j] && !vis[j])  
                cast[j] = cast[pos]+map[pos][j];  
        }  
    }  
}  
  
int main()  
{  
    int i,j,x,y,z,start,end;  
    while(~scanf("%d%d",&T,&D))  
    {  
    if(T==0&&D==0) break;
        for(i = 1; i<=T; i++)  
        {  
            for(j = 1; j<=T; j++)  
                map[i][j] = inf;  
           
        }  
        for(i=1;i<=D;i++)  
        {  
            scanf("%d%d%d",&x,&y,&z);  
                map[x][y] = map[y][x] = z;  
        }    
       n=T;
        Dijkstra(n);  
        printf("%d\n",cast[n]);  
    }  
  
    return 0;  
}  
