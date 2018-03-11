#include<bits/stdc++.h>
using namespace std;
int s[100]={1,1};
long long p(int x,int y){
	long long res=1;
	for(int i=1;i<=y;i++) res=res*x;
	return res;
}
int main(){
	int t;
	cin>>t;
	int n;
	long long sum=0;
	for(int i=2;i<=20;i++)
    {
    	s[i]=p(2,i-1)*(i+1)/2;
	}
	while(t--){
		scanf("%d",&n);		
		printf("%d\n",s[n]);
	}
}
