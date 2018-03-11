#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int mm[5020];

int main()
{
    int T;
    cin>>T;
    int n,m;
    int sum = 0;
    int flag = 0;
    while(T--){
        scanf("%d%d",&n,&m);
        int temp;
        for(int i = 0;i < n;i++){
            scanf("%d",&temp);
            sum += temp;
            mm[sum%m]++;
            if(mm[sum%m] == 2)flag = 1;
        }
        if(mm[0] != 0)flag = 1;
        if(n >= m)printf("YES\n");
        else{
            if(flag == 1)printf("YES\n");
            else{
                printf("NO\n");
            }
        }
        sum = 0;
        flag = 0;
        memset(mm,0,sizeof(mm));
    }
    return 0;
}
