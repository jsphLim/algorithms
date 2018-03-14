#include<bits/stdc++.h>
using namespace std;
int a[100010];
int dp[100010];
int main()
{
    int n,i,t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        int start,end,maxu,j1,j2;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        dp[0]=a[0];
        j1=j2=1;
		start=end=0;
        maxu=-100000;
        for(i=0;i<n;i++)
        {
            if(dp[i-1]+a[i]>=a[i])
            {
                dp[i]=dp[i-1]+a[i];
                end=i;
            }
            else
            {
                dp[i]=a[i];
                start=i;
                end=i;
            }
            if(maxu<dp[i])
            {
                maxu=dp[i];
                j1=start;
                j2=end;
            }
        }
        printf("Case %d:\n",kase++);
        printf("%d %d %d\n",maxu,j1+1,j2+1);
        if(t!=0)
          cout<<endl;

    }
}
