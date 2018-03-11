#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,kcase=1;;
    scanf("%d", &t);
    while(t--)
    {
        int m,n,ans;
        scanf("%d%d", &m, &n);
        if(m == 1 || n == 1)
            ans = m*n;
        else if(m == 2 || n == 2)
        {
            if(m == 2)
                if(n%4 < 2)
                    ans = (n/4)*4 + (n%4)*2;
                else
                    ans = (n/4)*4 + 4;
            if(n == 2)
                if(m%4 < 2)
                    ans = (m/4)*4 + (m%4)*2;
                else
                    ans = (m/4)*4 + 4;
        }
        else
            ans = (m*n+1)/2;
        printf("Case %d: %d\n", kcase++, ans);
    }
    return 0;
}
