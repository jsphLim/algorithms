#include <iostream>
#include <cstring>
using namespace std;
long long dp[2][15000000];
int main()
{
    int t,k,n,m,a[45];
    long long ans;
    cin>>t;
    k=0;
    while(t--)
    {
        k++;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<1500000;j++)
                dp[i%2][j]=dp[(i-1)%2][j]+dp[(i-1)%2][j^a[i]];
        ans=0;
        for(int i=m;(i<1500000);i++)
            ans+=dp[n%2][i];
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
