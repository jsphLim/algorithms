#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 0x3f3f3f3f
using namespace std;
struct plate
{
    int x1,x2,h;
}p[1010];
int maxn ,dp[1010][2],n;

int cmp(const plate &p1,const plate &p2)
{
    return p1.h<p2.h;
}


void lefttime(int i)
{
    int k = i-1;
    while(k>0 && p[i].h-p[k].h<=maxn)//如果有板子，并且高度差在允许范围内，则必须跳到这个板子上
    {
        if(p[k].x1<=p[i].x1 && p[k].x2>=p[i].x1)
        {
            dp[i][0]=(p[i].h-p[k].h)+min(dp[k][0]+p[i].x1-p[k].x1,dp[k][1]+p[k].x2-p[i].x1);
            return ;//必须是左下方的第一个板子，找到就结束
        }
        else k--;
    }
    //这个板子左下面没有板子，那么看他与地面的距离
    if(p[i].h-p[k].h > maxn) //如果与地面的距离太大
        dp[i][0]=INF;
    else //如果可以直接跳到地上
        dp[i][0]=p[i].h;
}

void righttime(int i)
{
    int k=i-1;
    while(k>0 && p[i].h-p[k].h<=maxn)
    {
        if(p[k].x1<=p[i].x2 && p[k].x2>=p[i].x2)
        {
            dp[i][1]=(p[i].h-p[k].h)+min(dp[k][0]+p[i].x2-p[k].x1,dp[k][1]+p[k].x2-p[i].x2);
            return ;
        }
        else k--;
    }
    if(p[i].h-p[k].h>maxn)
        dp[i][1]=INF;
    else //如果可以直接跳到地上
        dp[i][1]=p[i].h;
}

int shorttime()
{
    int i;
    for(i=1;i<=n+1;++i)
    {
        lefttime(i);
        righttime(i);
    }
    return min(dp[n+1][0],dp[n+1][1]);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        scanf("%d",&n);
        //初始化地面和当前位置
        scanf("%d%d%d",&p[n+1].x1,&p[n+1].h,&maxn);
        p[n+1].x2=p[n+1].x1;
        p[0].x1=-20000;
        p[0].x2=20000;
        p[0].h=0;
        //读取n个盘子
        for(i=1;i<=n;++i)
            scanf("%d%d%d",&p[i].x1,&p[i].x2,&p[i].h);
        sort(p,p+n+1,cmp);//板子从低到高排序
        printf("%d\n",shorttime());
    }

    return 0;
}

