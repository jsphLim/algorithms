#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[100005];

int main(){
	LL n,k;
	while(~scanf("%I64d%I64d",&n,&k)){
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	map<LL,LL> mp;
	mp.clear();
	LL cnt=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(mp[a[i]]==0) {cnt++;mp[a[i]*k]=1;}
	}
	cout<<cnt<<endl;
}
}