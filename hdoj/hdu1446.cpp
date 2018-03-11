#include<bits/stdc++.h>   
using namespace std;  
int main()  
{  
    int dp[21][192]={0};  
    int n,i,j,k;  
    for(i=0;i<21;i++) 
    {  
            dp[i][0]=1; 
    }  
    for(i=0;i<21;i++)  
    {  
        for(k=0;k<i;k++)  
        {  
            for(j=0;j<192;j++)  
            {  
                if(dp[k][j]==1)  
                    dp[i][(i-k)*k+j]=1;  
            }  
        }  
    }  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(i=0;i<n*(n-1)/2;i++)  
        {  
            if(dp[n][i])  
            cout<<i<<" ";  
  
        }  
        cout<<i<<endl;  
          
    }  
    return 0;  
}  


