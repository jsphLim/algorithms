#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define base 10000
#define max 120
using namespace std;
int catalan[max][max];
void big_mul(int *a,int n)     //大数乘法
{
    int temp=0;
    for(int i=0; i<max; i++)
    {
        temp+=a[i]*n;;
        a[i]=temp%base;
        temp/=base;
    }
}
void big_div(int *a,int n)      //大数除法
{
    int temp=0;
    for(int i=max-1; i>=0; i--)
    {
        temp=temp*base+a[i];
        a[i]=temp/n;
        temp%=n;
    }
}
void set()                             //求卡特兰数
{
    for(int i=0; i<max; i++)
        memset(catalan[i],0,sizeof(int)*max);
    catalan[0][0]=1;
    catalan[1][0]=1;
    for(int i=2; i<max; i++)
    {
        memcpy(catalan[i],catalan[i-1],sizeof(int)*max);
        big_mul(catalan[i],4*i-2);
        big_div(catalan[i],i+1);
    }
}
void output(int* a,int n)   //输出
{
    int i=n-1;
    while(a[i]==0) i--;
    printf("%d",a[i--]);
    while(i>=0) printf("%04d",a[i--]);
    printf("\n");
}
int main()
{
    set();
    int n;
    while(~scanf("%d",&n))
        output(catalan[n],n);
    return 0;
}
