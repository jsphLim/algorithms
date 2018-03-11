#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	int nn=1;
	while(t--){
		long long n;
		cin>>n;
		long long sum=(2+n)*(n-1)/2;
	//	cout<<sum<<endl;
		printf("Case #%d: %lld\n",nn++,sum);
	}
}
