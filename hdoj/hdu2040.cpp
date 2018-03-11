#include<bits/stdc++.h>
using namespace std;
int a(int n){
	int i,j=0;
	for(i=1;i<=n/2;i++){
		if(n%i==0){
			j=j+i;
		}
	}
	return j;
}
int main(){
	int t,m,n,i,j;
	cin>>t;
	while(t--){
		cin>>m>>n;
		 if(m==a(n)||a(m)==n) cout<<"YES"<<endl;
		 else cout<<"NO"<<endl;
	}
}
