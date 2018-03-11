#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		cout<<a[1]<<endl;
	}
}
