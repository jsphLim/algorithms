#include<stdio.h>
int main()
{
    int n;
    double a,b,c,k,d,x1,x2,x3,y1,y2,y3,area;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
            a=(y1-y2)/((x1*x1-x2*x2)-2*(x1*x1-x1*x2));
            b=-2*a*x1;
            c=y1-a*x1*x1+2*a*x1*x1;
            k=(y2-y3)/(x2-x3);
            d=y2-k*x2;
            area=(a*x3*x3*x3/3+b*x3*x3/2+c*x3-k*x3*x3/2-d*x3)-(a*x2*x2*x2/3+b*x2*x2/2+c*x2-k*x2*x2/2-d*x2);
            printf("%.2lf\n",area);
        }
    }
}
