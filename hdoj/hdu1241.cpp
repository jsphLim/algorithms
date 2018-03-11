#include <bits/stdc++.h>
using namespace std;  
char mp[105][105];  
int n, m, cnt;  
void dfs(int i, int j) 
{  
    if(mp[i][j]!='@' || i<0 || j<0 || i>=m || j>=n) return;  
    else 
    {  
        mp[i][j]='*'; 
        dfs(i-1, j-1);  
        dfs(i-1, j);  
        dfs(i-1, j+1);  
        dfs(i, j-1);  
        dfs(i, j+1);  
        dfs(i+1, j-1);  
        dfs(i+1, j);  
        dfs(i+1, j+1);  
    }  
}  
int main()  
{  
    int i, j;  
    while(scanf("%d%d",&m,&n)&&(m+n))  
    {  
        cnt = 0;  
        for(i=0; i<m;i++)  
            for(j=0; j<n;j++)    
                cin>>mp[i][j];  
        for(i=0; i<m;i++)  
        {  
            for(j=0; j<n;j++)  
            {  
                if(mp[i][j]=='@')  
                {  
                    dfs(i, j);  
                    cnt++;  
                }  
            }  
        }  
        cout<<cnt<<endl;  
    }  
   
    return 0;  
}
