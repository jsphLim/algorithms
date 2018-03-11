#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,m;
	while(cin>>n>>m&&(n+m)){
		if(n>m) swap(n,m);
		cout<<n*m*(m+n-2)+2*n*(n-1)*(3*m-n-1)/3<<endl;
	}
}
