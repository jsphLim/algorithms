#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n)
	{
		map<string,int> vitory;
		map<string,int>  lose;
		string a,b;
		for(int i=0;i<n;i++)
		{ 
			cin>>a>>b;
			if(lose[a]==0) vitory[a]=1;
			vitory[b]=0;
			lose[b]=1;
		}
		int sum=0;
		map<string ,int>::iterator its;
		for(its=vitory.begin();its!=vitory.end();its++)
		{
			if(its->second==1)sum++;
		}
		if(sum!=1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
