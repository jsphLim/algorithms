#include<bits/stdc++.h>
using namespace std;
long long f(int m,int n){
	long long x;
	if(m==0) return n+1;
	else if(m==1) return n+2;
	else if(m==2) return 2*n+3;
	else{
		if(n==1){
			x=13;
			return x;}
		else return f(m,n-1)*2+3;
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF){
		long long a=f(m,n);
		cout<<a<<endl;
	}
}
