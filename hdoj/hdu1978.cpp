#include<bits/stdc++.h>
using namespace std;
int a[100][1005];
int dp[1005][1005];
int cnt = 0;
int main(){
	int n,m,t;
	int i,j,k,s;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				for(k=i;k<=i+a[i][j];k++){
					for(s=j;s<=j+a[i][j];s++){
						if(s==j&&k==i) continue;
						if(k-i+s-j<=a[i][j]) dp[k][s]+=dp[i][j]%10000;
					}
				} 	
			} 
		}
		cout<<dp[n][m]%10000<<endl;
	} 
}
