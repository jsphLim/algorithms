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
		for(int i=1;i<=n;i++) dp[i][i]=1;
		
		for(int j=2;j<=n;j++)
		   for(int i=1;i<j;i++){
		   	  dp[i][j]=dp[i][j-1]+1;
		   	  for(int k=i;k<j;k++){
		   	  	if(ans[k]==ans[j]) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
				 }
		   } 
		   printf("Case %d: ",kase++);
		   cout<<dp[1][n]<<endl;
		   memset(dp,0,sizeof(dp));
	}
}