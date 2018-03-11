#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
const int mod = 10007;  
char str[1005];  
int dp[1005][1005];  
  
int main()  
{  
    int t,i,j,k,len,cas = 1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%s",str);  
        len = strlen(str);  
        for(i = 0; i<len; i++)  
            dp[i][i] = 1;  
        for(i = 1; i<len; i++)  
        {  
            for(j = i-1; j>=0; j--)  
            {  
                dp[j][i] = (dp[j+1][i]+dp[j][i-1]-dp[j+1][i-1]+mod)%mod; 
                if(str[i] == str[j])  
                    dp[j][i] = (dp[j][i]+dp[j+1][i-1]+1)%mod;
            }  
        }  
        printf("Case %d: %d\n",cas++,dp[0][len-1]);  
    }  
  
    return 0;  
}  
