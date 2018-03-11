#include <iostream> 
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
int main(void)
{
	int n,m,i;
	while(cin>>n>>m && n||m)
	{
		for(int i=sqrt(2*m);i>=1;i--)
		{
			int a=(m-((i-1)*i)/2)/i;
			if(m==a*i+(i*(i-1))/2&&a>0)
			cout<<'['<<a<<','<<a+i-1<<']'<<endl;
		}
		cout<<endl;
	}
	return 0;
}
