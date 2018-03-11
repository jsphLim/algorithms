#include<iostream>
using namespace std;
int main()
{
	long long a,b;
	while(scanf("%llX%llX",&a,&b)!=EOF)
	{
		a=a+b;
		if(a<0) {
		a=-a;
		printf("-%llX\n",a);
		}
		else printf("%llX\n",a);
	
	}
}
