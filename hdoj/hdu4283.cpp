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
                dp[i][j]��ʾ�ӵ�i���˵���j��������������С���ѣ���ֻ������j-i+1���ˣ�����Ҫ����ǰ���ж����ˣ� 
                ��ô����dp[i][j]�ĵ�i���ˣ����п��ܵ�1���ϳ���Ҳ���Ե�j-i+1���ϳ������ǵ�K���ϳ� 
                ����i+1֮���K-1�����������ϳ��ģ���ô�ͳ�����һ�������� dp[i+1][i+k-1]��ʾ�ڵ�i����֮ǰ�ϳ��� 
                ���ڵ�i���ˣ������ǵ�k���ϳ��ģ���ô��˿ֵ����a[i]*(k-1) 
                ������������ڵ�k+1��֮������ģ�Ҳ����һ��������dp[i+k][j]���������������ˣ��������ڵ�k+1��֮�����������ŭֵҪ����k*(sum[j]-sum[i+k-1]) 
                */  
            }  
        }  
        printf("Case #%d: %d\n",cas++,dp[1][n]);  
    }  
  
    return 0;  
}  
