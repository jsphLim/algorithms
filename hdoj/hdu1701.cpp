#include<iostream>
#include<cmath>
 using namespace std;
int main( void )
{
	int i,t;
	double p,q;
		cin>>t;
	while(t--)
	{
		cin>>p>>q;
		int a,b;
		for(i=1; ;i++)
		{
			a=(p*i)/100; b=(q*i)/100 ;
			
			if(b-a==1&&a<(p+i)) break;
		}
		cout<<i<<endl;
	}
	return 0;
}
