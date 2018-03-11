#include<iostream>
using namespace std;
int n,S;
int a[100];
void solve(){
	int res=n+1;
	int s=0,t=0,sum=0;
	while(1){
	while(t<n&&sum<S){
		sum+=a[t++];
	}
	if(sum<S) break;
	res=min(res,t-s);
	sum-=a[s++];
}
if(res>n) res=0;
cout<<res<<endl;
}
int main(){
	while(cin>>n>>S){
		for(int i=0;i<n;i++) cin>>a[i];
		solve();
	}
}
