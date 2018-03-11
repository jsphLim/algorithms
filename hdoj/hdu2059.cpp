#include<bits/stdc++.h> 
using namespace std;
#define INF 99999999
int main()
{
    int l;
    while(~scanf("%d",&l))
    {
        int n,c,t;
        scanf("%d%d%d",&n,&c,&t);
        int vr,vt1,vt2;
        scanf("%d%d%d",&vr,&vt1,&vt2);
        int p[105]= {0};
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&p[i]);
        }
        double tr=l*1.0/vr;
        double dp[150];
        for(int i=1; i<150; i++)
        {
            dp[i]=INF*2;
        }
        dp[0]=0;
        p[n+1]=l;
        for(int i=0; i<n+1; i++)
        {
            for(int j=i+1; j<=n+1; j++)
            {
                int x,y;
                if(c>p[j]-p[i])
                {
                    x=p[j]-p[i];
                    y=0;
                }
                else
                {
                    x=c;
                    y=p[j]-p[i]-c;
                }
                if(i==0)
                    dp[j]=min(dp[j],dp[i]+x*1.0/vt1+y*1.0/vt2);
                else
                    dp[j]=min(dp[j],dp[i]+t+x*1.0/vt1+y*1.0/vt2);
            }
        }
        if(dp[n+1]<tr)
            puts("What a pity rabbit!");
        else
            puts("Good job,rabbit!");
    }
}
