#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long a,b,c,d;
long long tmp;
long long sumx;
long long sumy;
int T;
void solve()
{
  sumx=0;
  sumy=0;

  for(int i=62;i>=0;i--)
  {
        tmp = 1LL<<i;
        if(tmp+sumx<=b && tmp+sumy>c)        sumx += tmp;
  else if(tmp+sumy<=d && tmp+sumx>a)        sumy += tmp;
        else if(tmp+sumx<=b && tmp+sumy<=d)
         {
            sumx += tmp;
            sumy += tmp;
         }
  }
  printf("%lld\n",sumx^sumy);
}
int main()
{
          scanf("%d",&T);
          while(T--)
          {
              scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
              solve();
          }
}
