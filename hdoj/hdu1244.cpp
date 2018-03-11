#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int a[1005],b[1005],dp[1005][1005],num[1005];
int main()
{
    int m,n;
    while(~scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
           scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
           scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++)
            num[i]=num[i-1]+a[i];//记录前i段的和；
        for(int i=1;i<=n;i++)//表示有多少个数（结尾的数）
           for(int j=1;j<=m;j++)//表示分成几段
           {
               dp[i][j]=dp[i-1][j];//若i不大于b[j]时直接取当有i-1个元素分成j段的结果
               if(i>=b[j])
                  dp[i][j]=max(dp[i-1][j],dp[i-b[j]][j-1]+num[i]-num[i-b[j]]);/*在（1）i-1个元素中去j段和（2）i-b[j]个元素取j+1段再加上*/  //背包思想 取或者不取 

           }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

