#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    long long  i,j,test,n;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("4\n");
            continue;
        }
        int d=sqrt(n*1.0)/sqrt(2.0);
        if(d*d*2>=n)
        {
            printf("%lld\n",4*d);
            continue;
        }
        if(d*d*2+(2*d-1)/2>=n)
        {
            printf("%lld\n",4*d+1);
            continue;
        }
        if(d*d*2+2*d>=n)
        {
            printf("%lld\n",4*d+2);
            continue;
        }
        if(d*d*2+3*d+0.5>=n)
        {
            printf("%lld\n",4*d+3);
            continue;
        }
        printf("%lld\n",(d+1)*4);
    }
    return 0;
}