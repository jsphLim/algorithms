#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int dp[1005][1005];
int ans[1006];
int main(){
	int t,n,kase=1;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&ans[i]);
		for(int i=1;i<=n;i++) dp[i][i]=1; //从i到i最坏需要一件衣服 
		
		for(int i=2;i<=n;i++)
		   for(int j=1;j<i;j++){
		   	  dp[j][i]=dp[j][i-1]+1; //从j到i等于从j到i-1加上一件 
		   	  for(int k=j;k<i;k++){
		   	  	if(ans[k]==ans[i]) dp[j][i]=min(dp[j][i],dp[j][k]+dp[k+1][i-1]); //如果区间内有一件衣服相同，那考虑能否少穿一次 
				 }
		   } 
		   printf("Case %d: ",kase++);
		   cout<<dp[1][n]<<endl;
		   memset(dp,0,sizeof(dp));
	}
}
