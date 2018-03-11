#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <math.h>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#define INF 0x3f3f3f3f
#define MAXN 1005
#define Mod 99999999
using namespace std;
int num[10005];
int count9(int n)
{
    int cnt=0;
    while(n!=0)
    {
        if(n%10==9)
            cnt++;
        n/=10;
    }
    return cnt;
}
bool isleap(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return true;
    return false;
}
void Init()
{
    int sum=0;
    for(int i=2000; i<=9999; ++i)
    {
        if(isleap(i))
            sum=count9(i)*366;
        else
            sum=count9(i)*365;
        sum+=30;
        sum+=11*3;
        if(isleap(i))
            sum+=3;
        else
            sum+=2;
        num[i]=sum;
    }
}
int mon1[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mon2[]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    Init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int y1,m1,d1,y2,m2,d2;
        int ans=0;
        scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
        if(y1==y2)
        {
            int days=0;
            for(int i=m1+1; i<m2; ++i)
            {
                if(i==2&&isleap(y1))
                    ans+=3;
                else if(i==2&&!isleap(y1))
                    ans+=2;
                else if(i==9)
                    ans+=33;
                else
                    ans+=3;
                if(!isleap(y1))
                    days+=mon1[i];
                else
                    days+=mon2[i];
            }
            if(m1==m2)
            {
                for(int i=d1; i<=d2; ++i)
                {
                    ans+=count9(i);
                    days++;
                    if(m1==9)
                        ans++;
                }
                ans=ans+days*count9(days);
                printf("%d\n",ans);
            }
            else
            {
                if(!isleap(y1))
                {
                    for(int i=d1; i<=mon1[m1]; ++i)
                    {
                        ans+=count9(i);
                        days++;
                        if(m1==9)
                            ans++;
                    }
                }
                else
                {
                    for(int i=d1; i<=mon2[m1]; ++i)
                    {
                        ans+=count9(i);
                        days++;
                        if(m1==9)
                            ans++;
                    }
                }
                for(int i=1; i<=d2; ++i)
                {
                    ans+=count9(i);
                    days++;
                    if(m2==9)
                        ans++;
                }
                ans=ans+days*count9(y1);
                printf("%d\n",ans);
            }
        }
        else
        {
            for(int i=y1+1; i<y2; ++i)
                ans+=num[i];
            int days1=0,days2=0;
            for(int i=m1+1; i<=12; ++i)
            {
                if(i==2&&isleap(y1))
                    ans+=3;
                else if(i==2&&!isleap(y1))
                    ans+=2;
                else if(i==9)
                    ans+=33;
                else
                    ans+=3;
                if(!isleap(y1))
                    days1+=mon1[i];
                else
                    days1+=mon2[i];
            }
            if(!isleap(y1))
            {
                for(int i=d1; i<=mon1[m1]; ++i)
                {
                    ans+=count9(i);
                    days1++;
                    if(m1==9)
                        ans++;
                }
            }
            else
            {
                for(int i=d1; i<=mon2[m1]; ++i)
                {
                    ans+=count9(i);
                    days1++;
                    if(m1==9)
                        ans++;
                }
            }
            ans=ans+days1*count9(y1);

            for(int i=1; i<m2; ++i)
            {
                if(i==2&&isleap(y2))
                    ans+=3;
                else if(i==2&&!isleap(y2))
                    ans+=2;
                else if(i==9)
                    ans+=33;
                else
                    ans+=3;
                if(!isleap(y2))
                    days2+=mon1[i];
                else
                    days2+=mon2[i];
            }
            for(int i=1; i<=d2; ++i)
            {
                ans+=count9(i);
                days2++;
                if(m2==9)
                    ans++;
            }
            ans=ans+days2*count9(y2);
            printf("%d\n",ans);
        }
    }
    return 0;
}
