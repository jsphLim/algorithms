#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n;
long long a[N];
int judge(long long mid)
{
    long long ans=0;
    for(int i=1; i<=n; ++i)
    {
        if(a[i]>mid)return 0;
        ans+=mid-a[i];
    }
    if(ans>=mid) return 1;
    return 0;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        long long sum=0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        long long ans=0,left=0,right=sum;
        while(left<=right)
        {
            long long mid=(left+right)>>1;
            if(judge(mid))  ans=mid,right=mid-1;
            else    left=mid+1;
        }
        printf("%I64d\n",ans);
    }
}