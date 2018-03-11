#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1000;//
bool vis[maxn];
ll prime[maxn/10];
int tot;
void getprime()//因为n的范围是1e14，打表只需要打到sqrt(n)即可，最多只可能有一个素因子大于sqrt(n)，最后特判一下即可；
{
    memset(vis,true,sizeof(vis));
    tot=0;
    for(ll i=2;i<maxn;i++)
    {
        if(vis[i])
        {
        prime[tot++]=i;
        for(ll j=i*i;j<maxn;j+=i)
        {
            vis[j]=false;
        }
        }
    }
}
/*void Eulerprime()
{
    memset(vis,true,sizeof(vis));
    int tot=0;
    for(int i=2;i<maxn;i++)
    {
        if(vis[i]) prime[tot++]=i;
        for(int j=0;j<tot&&prime[j]*i<maxn;j++)
        {
            vis[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}*/
int a[1000],b[1000];
int cnt=0;
void sbreak(ll n)//正整数唯一分解
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cnt=0;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            a[cnt]=prime[i];
            while(n%prime[i]==0)
            {
                b[cnt]++;
                n/=prime[i];
            }
            cnt++;
        }
    }
    if(n!=1)
    {
        a[cnt]=n;
        b[cnt]=1;
        cnt++;//为了使两种情况分解后素因子下标都是0~cnt-1;
    }
}
int pow_mod(int m,int n)
{
    ll pw=1;
    while(n)
    {
        if(n&1) pw*=m;
        m*=m;
        n/=2;
    }
    return pw;
}
int kase;
int main()
{
    int T;
    ll n;
    getprime();
    scanf("%d",&T);
    kase=0;
    while(T--)
    {
        scanf("%lld",&n);
        sbreak(n);
        ll sum=1;
        for(int i=0;i<cnt;i++)
        {
            ll cur=0;
            for(int j=0;j<=b[i];j++)
            {
                cur+=pow_mod(a[i],j);
            }
            sum*=cur;
        }
         printf("%lld\n",sum-n);
    }
}
