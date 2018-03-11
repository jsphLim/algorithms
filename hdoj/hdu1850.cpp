#include<iostream>
const int MAX=101;
int s[MAX];
using namespace std;
int main()
{
	int n,m,i,sum;
	while(cin>>n,n)
	{
		m=0;
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin>>s[i];
			m^=s[i];
		}
		for(i=1;i<=n;i++)
		{
			if((m^s[i])<s[i])
			sum+=1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
