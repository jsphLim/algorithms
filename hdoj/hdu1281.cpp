#include <bits/stdc++.h> 
using namespace std;  
const int N = 105;  
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
    int Case = 1;  
    while(scanf("%d%d%d", &n, &m, &k) != EOF)  
    {  
        memset(mp, 0, sizeof(mp));  
  
        for(int i = 1; i <= k; i++)  
        {  
            scanf("%d%d", &x[i], &y[i]);  
            mp[x[i]][y[i]] = 1;  
        }  
        int ans = mat();  
        int sum = 0;  
        for(int i = 1; i <= k; i++)  
        {  
            mp[x[i]][y[i]] = 0;  
            int res = mat();  
            mp[x[i]][y[i]] = 1;  
            if(res < ans) sum++;  
        }  
        printf("Board %d have %d important blanks for %d chessmen.\n", Case++, sum, ans);  
    }  
    return 0;  
}  
