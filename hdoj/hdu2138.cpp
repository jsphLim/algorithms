#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
bool sushu(int n){
     int i;
	for(i=2;i*i<=n;i++)
		if(n%2==0) return false;
	return true;
}
int main(){
	int n,sum,m;
	while(scanf("%d",&n),n){
		sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		if(sushu(m)&&m!=1) sum++;
	}
	cout<<sum<<endl;	
	}
	
}


