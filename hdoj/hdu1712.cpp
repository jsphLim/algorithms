#include<bits/stdc++.h>
using namespace std;
int v[1000][1000];
int dp[1005];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)&&(m+n)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=m;j++) scanf("%d",&v[i][j]);
		   
		   for(int i=1;i<=n;i++)
		       for(int j=m;j>=1;j--)
		          for(int p=1;p<=j;p++){
		          	dp[j]=max(dp[j],dp[j-p]+v[i][p]);
			  }
			  int ans=-1;
			  for(int i=1;i<=m;i++){
			  	if(dp[i]>ans) ans=dp[i];
			  }
			  cout<<ans<<endl;
	}
}
