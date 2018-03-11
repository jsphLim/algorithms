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
    while(k>0 && p[i].h-p[k].h<=maxn)//����а��ӣ����Ҹ߶Ȳ�������Χ�ڣ�������������������
    {
        if(p[k].x1<=p[i].x1 && p[k].x2>=p[i].x1)
        {
            dp[i][0]=(p[i].h-p[k].h)+min(dp[k][0]+p[i].x1-p[k].x1,dp[k][1]+p[k].x2-p[i].x1);
            return ;//���������·��ĵ�һ�����ӣ��ҵ��ͽ���
        }
        else k--;
    }
    //�������������û�а��ӣ���ô���������ľ���
    if(p[i].h-p[k].h > maxn) //��������ľ���̫��
        dp[i][0]=INF;
    else //�������ֱ����������
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
    else //�������ֱ����������
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
        //��ʼ������͵�ǰλ��
        scanf("%d%d%d",&p[n+1].x1,&p[n+1].h,&maxn);
        p[n+1].x2=p[n+1].x1;
        p[0].x1=-20000;
        p[0].x2=20000;
        p[0].h=0;
        //��ȡn������
        for(i=1;i<=n;++i)
            scanf("%d%d%d",&p[i].x1,&p[i].x2,&p[i].h);
        sort(p,p+n+1,cmp);//���Ӵӵ͵�������
        printf("%d\n",shorttime());
    }

    return 0;
}

