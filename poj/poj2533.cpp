#include<iostream>
using namespace std;
int n,ans;
int dp[100005],a[100005];
int LIS(){
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]) dp[i] = max(dp[i],dp[j]+1);
		}
	}
	ans=-11;
	for(int i=0;i<n;i++) ans=max(ans,dp[i]);
	return ans;
}
int main(){
	 while(cin>>n){
	 	for(int i=0;i<n;i++) cin>>a[i];
	 	LIS();
	 	cout<<ans<<endl;
	 }
}
