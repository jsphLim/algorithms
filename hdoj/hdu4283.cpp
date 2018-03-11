#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
const int inf = 10000000;  
  
int n,a[105],sum[105],dp[105][105];  
  
int main()  
{  
    int t,i,j,k,l,cas = 1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        memset(sum,0,sizeof(sum));  
        for(i = 1; i<=n; i++)  
        {  
            scanf("%d",&a[i]);  
            sum[i] = sum[i-1]+a[i];  
        }  
        memset(dp,0,sizeof(dp));  
        for(i = 1; i<=n; i++)  
        {  
            for(j = i+1; j<=n; j++)  
                dp[i][j] = inf;  
        }  
        for(l = 1; l<n; l++)  
        {  
            for(i = 1,j=l+1; i<n; i++,j++)  
            {  
                //j = i+l;  
                for(k = 1; k<=j-i+1; k++)  
                    dp[i][j] = min(dp[i][j],dp[i+1][i+k-1]+dp[i+k][j]+k*(sum[j]-sum[i+k-1])+a[i]*(k-1));  
                /* 
                dp[i][j]表示从第i个人到第j个人这段区间的最小花费（是只考虑这j-i+1个人，不需要考虑前面有多少人） 
                那么对于dp[i][j]的第i个人，就有可能第1个上场，也可以第j-i+1个上场。考虑第K个上场 
                即在i+1之后的K-1个人是率先上场的，那么就出现了一个子问题 dp[i+1][i+k-1]表示在第i个人之前上场的 
                对于第i个人，由于是第k个上场的，那么屌丝值便是a[i]*(k-1) 
                其余的人是排在第k+1个之后出场的，也就是一个子问题dp[i+k][j]，对于这个区间的人，由于排在第k+1个之后，所以整体愤怒值要加上k*(sum[j]-sum[i+k-1]) 
                */  
            }  
        }  
        printf("Case #%d: %d\n",cas++,dp[1][n]);  
    }  
  
    return 0;  
}  
