#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
char s[102];
int dp[102][102];
int main()
{
    int i, j, k, w;
    while(scanf("%s",s))
    {
        if(s[0]=='e') break;
        memset(dp,0,sizeof(dp));
        int len= strlen(s);
        for(k=1;k<len;k++) //表示区间长度，从0-len更新
        {
            for(i=0,j=k;j<len;i++,j++)
            {
                if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']') //匹配
                    dp[i][j]=dp[i+1][j-1]+2;
                for(w=i;w<j;w++)   //区间最值合并
                    dp[i][j]=max(dp[i][j],dp[i][w]+dp[w+1][j]);
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}
