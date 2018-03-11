#include <bits/stdc++.h> 
using namespace std;  
const int N = 110;  
int mp[N][N], use[N], vis[N];  
int m, n, k, x[N * N], y[N * N];  
int find(int x)  
{  
    for(int j = 1; j <= m; j++)  
    {  
        if(mp[x][j] && !vis[j])  
        {  
            vis[j] = 1;  
            if(use[j] == 0 || find(use[j]) == 1)  
            {  
                use[j] = x;  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
  
int mat()  
{  
    int sum = 0;  
    memset(use, 0, sizeof(use));  
    for(int i = 1; i <= n; i++)  
    {  
        memset(vis, 0, sizeof(vis));  
        if(find(i)) sum++;  
    }  
    return sum;  
}  
int main()  
{  
    while(~scanf("%d",&n)&&n)  
    {  
        cin>>m>>k;  
        memset(mp,0,sizeof(mp));  
        for(int i=0;i<k;i++)  
        {  
            int t,u,v;  
            scanf("%d%d%d",&t,&u,&v);  
            if(u&&v)  mp[u][v]=1;  
        }  
        cout<<mat()<<endl;  
    }  
}  


