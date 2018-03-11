#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
	double n,m;
	char c;
	while(~scanf("%lf",&n))
	{
		c=getchar();
		if(c=='\n' &&n==0)
			break;
		stack<double>s;
		s.push(n);
		scanf("%c",&c);
		while(~scanf("%lf",&n))
		{ 
			if(c=='*')
			{
				m=s.top();
				m*=n;
				s.pop();
				s.push(m);
			}
			if(c=='/')
			{
				m=s.top();
				m/=n;
				s.pop();
				s.push(m);
			}
			if(c=='+')
				s.push(n);
			if(c=='-')
				s.push(0-n);
			if(getchar()=='\n')
				break;
			c=getchar();
		}
		double sum=0;
		while(!s.empty())
		{
			sum+=s.top();
			s.pop();
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
