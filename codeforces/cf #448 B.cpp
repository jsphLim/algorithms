#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int getc(long long l,long long r,long long k){
	int left = min(l,r);
	int right = max(l,r);
	if(left==0||left%k==0){
		return right/k-left/k+1;
	}
	else{
		return right/k-left/k;
	}
}
int main(){
   long long n,x,k;
   cin>>n>>x>>k;
   for(int i=0;i<n;i++) scanf("%lld",&a[i]);
   long long counts=0;
   for(int i=0;i<n;i++){
   	for(int j=0;j<n;j++){
   		long long res = getc(a[i],a[j],x);
   	 if(a[j]>=a[i]&&res==k) counts++;
   }
}
	cout<<counts<<endl;
}
