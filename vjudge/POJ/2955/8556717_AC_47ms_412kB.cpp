#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[102];
int dp[102][102];
int main()
{
    int i, j, k, x;
    while(gets(s)!=NULL)
    {
        if(s[0]=='e')break;
        memset(dp,0,sizeof(dp));
        int len= strlen(s);
        for(k=1;k<len;k++) //表示区间长度，从0-len更新
        {
            for(i=0,j=k;j<len;i++,j++)
            {
                if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']') //匹配
                    dp[i][j]=dp[i+1][j-1]+2;
                for(x=i;x<j;x++)   //区间最值合并
                    dp[i][j]=max(dp[i][j],dp[i][x]+dp[x+1][j]);
                //printf("dp[%d][%d]=%d ",i,j,dp[i][j]);
            }
            //puts("");
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}