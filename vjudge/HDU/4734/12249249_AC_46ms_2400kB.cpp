#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>  
#include<algorithm>  
#include<math.h>  
#include<queue>  
#include<stack>  
using namespace std;  
typedef long long ll;  
int dp[20][9300];  
int digit[20];  
int dfs(int pos,int st,bool limit)  
{  
    if(pos==0)return st>=0;  
    if(st<0)return 0;  
    if(!limit&&dp[pos][st]!=-1)return dp[pos][st];  
    int ans=0;  
    int end=limit?digit[pos]:9;  
    for(int i=0; i<=end; i++)  
        ans+=dfs(pos-1,st-i*(1<<(pos-1)),limit&&(i==end));  
    if(!limit)  
        dp[pos][st]=ans;  
    return ans;  
}  
int f(int x)  
{  
    int ans=0;  
    int i=0;  
    while(x)  
        ans+=(x%10)*(1<<(i++)),x/=10;  
    return ans;  
}  
int get(int a,int b)  
{  
    int bj=0;  
    while(b)  
        digit[++bj]=b%10,b/=10;  
    return dfs(bj,f(a),1);  
}  
int main()  
{  
    int t,o=1;  
    memset(dp,-1,sizeof(dp));  
    scanf("%d",&t);  
    while(t--)  
    {  
        int a,b;  
        scanf("%d%d",&a,&b);  
        printf("Case #%d: %d\n",o++,get(a,b));  
    }  
    return 0;  
}  