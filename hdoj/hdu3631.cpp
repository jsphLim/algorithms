#include <bits/stdc++.h>  
#define inf 99999999  
using namespace std;  
int mp[350][350];  
int vis[350];  
int n,m,q;  
void floyd(int k)  
{  
    int i,j;  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            if(mp[i][j]>mp[i][k]+mp[k][j])  
                mp[i][j]=mp[i][k]+mp[k][j];  
        }  
    }  
}  
int main()  
{  

    int kcase=1;  
    while(scanf("%d%d%d",&n,&m,&q)&&n+m+q)  
    {    
        int i,j;  
        memset(vis,0,sizeof(vis));  
        for(i=0;i<=n;i++)  
            for(j=0;j<=n;j++)  
                mp[i][j]=(i==j?0:inf);  
        for(i=0;i<m;i++)  
        {  
            int a,b,c;  
            scanf("%d%d%d",&a,&b,&c);  
            if(c<mp[a][b])  
                mp[a][b]=c;  
        }  
        if(kcase!=1)  
            printf("\n");  
        printf("Case %d:\n",kcase++);  
        for(i=0;i<q;i++)  
        {  
            int flag;  
            scanf("%d",&flag);  
            if(flag==0)  
            {  
                int u;  
                scanf("%d",&u);  
                if(vis[u]==1)  
                    printf("ERROR! At point %d\n",u);  
                else  
                {  
                    vis[u]=1;  
                    floyd(u);  
                }  
            }  
            else  
            {  
                int s,d;  
                scanf("%d%d",&s,&d);  
                if(vis[s]==0||vis[d]==0)  
                    printf("ERROR! At path %d to %d\n",s,d);  
                else if(mp[s][d]>=inf)  
                    printf("No such path\n");  
                else  
                    printf("%d\n",mp[s][d]);  
            }  
        }  
    }  
    return 0;  
}  
