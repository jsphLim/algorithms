#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXV 60010
using namespace std;
int d[MAXV],V;

void bag01(int c,int w)//01背包
{
    int i;
    for(i=V;i>=c;i--)
    {
        if(d[i]<d[i-c]+w)
        {
            d[i]=d[i-c]+w;
        }
    }
}

void bagall(int c,int w)//完全背包
{
    int i;
    for(i=c;i<=V;i++)
    {
        if(d[i]<d[i-c]+w)
        {
            d[i]=d[i-c]+w;
        }
    }
}

void multbag(int c,int w,int n)//多重背包
{
    if(c*n>=V)
    {
        bagall(c,w);return ;
    }
    int k=1;
    while(k<=n)
    {
        bag01(k*c,k*w);
        n=n-k;
        k=k*2;
    }
    bag01(n*c,n*w);
}

int main()
{
    int n[6],sumv,i,k=1;
    while(cin>>n[0]>>n[1]>>n[2]>>n[3]>>n[4]>>n[5],n[0]+n[1]+n[2]+n[3]+n[4]+n[5])
    {
        memset(d,0,sizeof(d));
        sumv=n[0]+n[1]*2+n[2]*3+n[3]*4+n[4]*5+n[5]*6;
        if(sumv%2==1)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",k++);
            continue;
        }
        V=sumv/2;
        for(i=0;i<6;i++)
        {
            if(n[i]) multbag(i+1,i+1,n[i]);
        }
        if(V==d[V]) printf("Collection #%d:\nCan be divided.\n\n",k++);
        else printf("Collection #%d:\nCan't be divided.\n\n",k++);
    }
    return 0;
}
