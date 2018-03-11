#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t;
	double h,m,s,sum,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&h,&m,&s);
		if(h>12)
	     h-=12;
	     m=m+1.0*s/60;
	     h=h+1.0*m/60;
	     h=h*30;
	     m=m*6;
	    double ans=fabs(m-h);
	    if(ans>180) ans=360-ans;
	    cout<<(int)ans<<endl;
	}
	return 0;
}

