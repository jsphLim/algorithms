#include<bits/stdc++.h>
using namespace std;
int dp[100005][12];
struct node{
	int t;
	int x;
}ans[100005];
int main(){
	int n;
	while(cin>>n,n){
		memset(dp,0,sizeof(dp));
		int times=-1;
		for(int i=0;i<n;i++) {scanf("%d%d",&ans[i].x,&ans[i].t);dp[ans[i].t][ans[i].x+1]++;  times=max(times,ans[i].t);};
		for(int i=times;i>=0;i--){
			for(int j=1;j<=11;j++)
				dp[i][j]+=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
		}
				cout<<dp[0][6]<<endl;
		}
}
