#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		cout<<(100-a[0])*(100-a[0])<<endl;
	}
}
