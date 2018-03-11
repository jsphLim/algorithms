#include <iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=int(1e5)+9;
int h[N];
int n;
int main()
{
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)scanf("%d",&h[i]);
        long long ans=0;
        stack<int>s;s.push(0);h[++n]=0;
        for(int i=1;i<=n;i++)
        {
            while(h[i]<h[s.top()])
            {
                long long a=h[s.top()];s.pop();
                long long b=i-s.top()-1;
                if(a*b>ans)ans=a*b;
            }
            s.push(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
