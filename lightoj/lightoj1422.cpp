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
		for(int i=1;i<=n;i++) dp[i][i]=1; //��i��i���Ҫһ���·� 
		
		for(int i=2;i<=n;i++)
		   for(int j=1;j<i;j++){
		   	  dp[j][i]=dp[j][i-1]+1; //��j��i���ڴ�j��i-1����һ�� 
		   	  for(int k=j;k<i;k++){
		   	  	if(ans[k]==ans[i]) dp[j][i]=min(dp[j][i],dp[j][k]+dp[k+1][i-1]); //�����������һ���·���ͬ���ǿ����ܷ��ٴ�һ�� 
				 }
		   } 
		   printf("Case %d: ",kase++);
		   cout<<dp[1][n]<<endl;
		   memset(dp,0,sizeof(dp));
	}
}
