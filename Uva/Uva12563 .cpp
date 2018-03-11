#include<bits/stdc++.h>
using namespace std;
int w[60];
int dp[100][100];
int main(){
	int t,num,T,minu,i,j;
	cin>>t;
	int kcase=1;
	while(t--){
		cin>>num>>T;
		for(i=0;i<num;i++) scanf("%d",&w[i]);
		memset(dp,0,sizeof(dp));
		for(i=num-1;i>=0;i--){
			for(j=0;j<=T-1;j++){
				if(j<w[i]) dp[i][j]=dp[i+1][j];
				else{
					dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+w[i]);
					
				}
			}
		}
		int sum=11*60+18;
		sum+=dp[0][T-1];
		memset(dp,0,sizeof(dp));
		for(i=num-1;i>=0;i--){
			for(j=0;j<=T-1;j++){
				if(j<w[i]) dp[i][j]=dp[i+1][j];
				else{
					dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+1);
					
				}
			}
		}
		int sums=1;
		sums+=dp[0][T-1];
		cout<<"Case "<<kcase++<<": ";
		cout<<sums<<" "<<sum<<endl;
	}
}
