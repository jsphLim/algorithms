#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct su
{
    int t,x;
}a[10010];
bool cmp(su a,su b)
{
    return a.t<b.t;
}
int main()
{
    int t,k,n,i;
    double maxsum;
    scanf("%d",&t);
    for (k=1;k<=t;k++)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            scanf("%d%d",&a[i].t,&a[i].x);
        sort(a+1,a+n+1,cmp);
        maxsum=0;
        for (i=2;i<=n;i++)
            if (abs(a[i].x-a[i-1].x)/(double)(a[i].t-a[i-1].t)>maxsum) 
                maxsum=abs(a[i].x-a[i-1].x)/(double)(a[i].t-a[i-1].t);
        printf("Case #%d: %.2lf\n",k,maxsum);
    }
}
