#include <bits/stdc++.h>
using namespace std;
int a[2100], b[2100], dp[2100] = {0};
int main()
{
    int t, n;
    int hour, mins, second;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        for (int i = 2; i <= n; ++i)
            scanf("%d", &a[i]);
        dp[1] = b[1];
        for (int i = 2; i <= n; ++i)
            dp[i] = min(dp[i-1]+b[i], dp[i-2]+a[i]);
        hour = dp[n]/3600;
        mins = dp[n]%3600/60;
        second = dp[n]%60;
        printf("%02d:%02d:%02d%s\n", (8+hour)%24, mins, second, (8+hour)%24>12?" pm":" am");
    }
    return 0;
}
