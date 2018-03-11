#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
char s1[105],s2[105];  
int dp[105][105];//dp[i][j]为i~j的刷法  
int ans[105],i,j,k,len;  
  
int main()  
{  
    while(~scanf("%s%s",s1,s2))  
    {  
        len = strlen(s1);  
        memset(dp,0,sizeof(dp));  
        for(j = 0; j<len; j++)  
        {  
            for(i = j; i>=0; i--)//j为尾，i为头  
            {  
                dp[i][j] = dp[i+1][j]+1;//先每个单独刷  
                for(k = i+1; k<=j; k++)//i到j中间所有的刷法  
                {  
                    if(s2[i]==s2[k])  
                        dp[i][j] = min(dp[i][j],(dp[i+1][k]+dp[k+1][j]));//i与k相同，寻找i刷到k的最优方案  
                }  
            }  
        }  
        for(i = 0; i<len; i++)  
            ans[i] = dp[0][i];//根据ans的定义先初始化  
        for(i = 0; i<len; i++)  
        {  
            if(s1[i] == s2[i])  
                ans[i] = ans[i-1];//如果对应位置相等，这个位置可以不刷  
            else  
            {  
                for(j = 0; j<i; j++)  
                    ans[i] = min(ans[i],ans[j]+dp[j+1][i]);//寻找j来分割区间得到最优解  
            }  
        }  
        printf("%d\n",ans[len-1]);  
    }  
  
    return 0;  
}  
