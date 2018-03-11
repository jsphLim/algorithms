#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int dp[3000100];

int MyMax(int a,int b)
{
    return (a>b?a:b);
}

int main()
{
    int n,m,top;
    double q;
    while((scanf("%lf%d",&q,&n)!=EOF)&&(n!=0))
    {
        char type;
        double price;
        int i,j,x,a,b,c,tag,top;
        int money[35];
        top=(int)(q*100);
        memset(dp,0,sizeof(dp));
        memset(money,0,sizeof(money));
        for(i=1;i<=n;i++)
        {
            a=b=c=tag=0;
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%*c%c:%lf",&type,&price);
                x=(int)(price*100);
                if(type=='A'||type=='B'||type=='C')
                {
                    a+=x;
                }
                else if(type=='B')
                {
                    b+=x;
                }
                else if(type=='C')
                {
                    c+=x;
                }
                else
                {
                    tag=1;
                }
            }
            if(tag!=1&&a+b+c<=100000&&a<=60000&&b<=60000&&c<=60000)
            {
                money[i]=a+b+c;
            }
            else
            {
                money[i]=top+1;
            }
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=top;j>=money[i];j--)
            {
                dp[j]=MyMax(dp[j],dp[j-money[i]]+money[i]);
            }
        }
        printf("%.2lf\n",dp[top]/100.0);
    }
    return (0);
}
