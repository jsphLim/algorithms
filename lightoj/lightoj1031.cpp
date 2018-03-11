#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int dp[1005][1005];
int a[1005];
int sum[1005];
int main(){
	int t,n,kase=1;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			dp[i][i]=a[i];
		} 
		
		for(int i=1;i<=n;i++){   
		   for(int j=1;j<=n-i;j++){
		   	  int k=j+i;
		   	  dp[j][k]=sum[k]-sum[j-1];
		   	  for(int w=j;w<k;w++){
		   	  	dp[j][k]=max(dp[j][k],max(sum[w]-sum[j-1]-dp[w+1][k],sum[k]-sum[w]-dp[j][w]));
			 }
	     }
	 }
	     printf("Case %d: %d\n",kase++,dp[1][n]);
	}
} 
