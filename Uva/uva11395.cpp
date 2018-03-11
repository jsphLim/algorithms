#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+5;

bool vis[N];
int prime[N],cnt;
void is_prime()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(int j=i+i;j<N;j+=i)
                vis[j]=1;
        }
    }
}

bool is_even(long long n)
{
    for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++)
    {
        int count=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                count++;
            }
            if(prime[i]&1)
            {
                if(count&1)
                    return true;
            }
        }
    }
    if(n>1&&(n&1))
        return true;
    return false;
}

int main()
{
    int t;
    cin>>t;
    is_prime();
    for(int kase=1;kase<=t;kase++)
    {
        long long n;
        cin>>n;
        long long count=0;
        for(long long i=1;i<=n;i++)
        {
            if(is_even(i))
                count++;
        }
        printf("Case %d: %d\n",kase,count);
    }
}
