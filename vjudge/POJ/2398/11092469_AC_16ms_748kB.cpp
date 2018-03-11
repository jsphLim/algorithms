#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef  struct  board
{
    double  x1;
    double  x2;
} bo;
inline  bool cross(const double  &x1,const double  &x2,const  double  &x3,const double &x4,const double y1,const double  y2,const double x0,const double y0)
{
    double  m1,m2;
    bool  flag;
    m1=x1+(x2-x1)*(y0-y1)/(y2-y1);
    m2=x3+(x4-x3)*(y0-y1)/(y2-y1);
    if((m1<=x0)&&(m2>=x0)) flag=true;
    else  flag=false;
    return  flag;
}
bool cmp(board x,board y)
{
    return x.x1<y.x1;
}
int main()
{
    bo  b[2050];
    int i,j,m,n;
    double x[2],y[2],x0,y0;
    int cnt[2050];
    //freopen("1.txt","r",stdin);
    while(scanf("%d",&n),n)
    {
        scanf("%d%lf%lf%lf%lf",&m,&x[0],&y[0],&x[1],&y[1]);
        b[0].x1=x[0];
        b[0].x2=x[0];
        b[n+1].x1=x[1];
        b[n+1].x2=x[1];
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&b[i].x1,&b[i].x2);
        memset(cnt,0,sizeof(cnt));
        sort(b,b+n+1,cmp);
        for(i=0;i<m;i++)
        {
            scanf("%lf%lf",&x0,&y0);
            for(j=0;j<=n;j++)
            {
                if(cross(b[j].x1,b[j].x2,b[j+1].x1,b[j+1].x2,y[0],y[1],x0,y0))
                {
                    cnt[j]++;
                    break;
                }
            }
        }
        int cnt1[2050];
        memset (cnt1,0,sizeof(cnt1));
       for(i=0;i<=n;i++)
       {
       cnt1[cnt[i]]++;
       }
      printf("Box\n");
       for(i=1;i<=m;i++)
       {
           if(cnt1[i]>0)
        printf("%d: %d\n",i,cnt1[i]);
       }
   }
return 0;
}
