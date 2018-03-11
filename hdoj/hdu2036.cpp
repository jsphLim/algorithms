#include <stdio.h>
#include <math.h>
typedef struct node
{
	double x,y;
}node;
node s[1001];

double S(node x,node y,node z)
{
	return (y.x-x.x)*(z.y-x.y)-(y.y-x.y)*(z.x-x.x);
}
int main()
{
	int n,i;
	double res;
	while(scanf("%d",&n),n)
	{
		res=0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&s[i].x,&s[i].y);
		for(i=1;i<n-1;i++)
			res+=S(s[0],s[i],s[i+1]);
		printf("%.1lf\n",res/2.0);
	}
	return 0;
}
