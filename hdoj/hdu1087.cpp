#include<bits/stdc++.h>
using namespace std;
int a[101010];
int dp[101010];
int main(){
	int n,i,j;
	while(scanf("%d",&n),n){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		int maxx=0;
	    dp[0]=a[0];
		for(i=1;i<n;i++){
			dp[i]=a[i];
			for(j=0;j<i;++j){
				if(a[i]>a[j]){
					dp[i]=max(dp[i],dp[j]+a[i]);
				}
			}
		}
		   sort(dp,dp+n);
		   cout<<dp[n-1]<<endl;
		
	}
}
