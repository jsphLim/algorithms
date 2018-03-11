#include<bits/stdc++.h>
using namespace std;
int mp[1050][1050];
int dp[1050][1050];	
int main(){
	int t,n,m,kase=1;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=m;j++){
		   	scanf("%d",&mp[i][j]); 
		   }
		   memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=m;j++){
		   	dp[i][j]=mp[i][j]+max(dp[i-1][j],dp[i][j-1]);
		   }
		   printf("Scenario #%d:\n",kase++);
		   cout<<dp[n][m]<<endl<<endl;
	}
} 
