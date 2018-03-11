#include<stdio.h>
#define MOD 2009
#define MAXN 10000
int f[MAXN];
   
int main()
{   f[1]=1;
    f[2]=7;
    for(int i=3;i<4020;i++)
    {
        f[i]=f[i-2]+3*i*i-3*i+1;
        f[i]%=MOD;
    }
    int n;
    while(scanf("%d",&n),n)
    {
        printf("%d\n",f[n%4018]);
    }
}
