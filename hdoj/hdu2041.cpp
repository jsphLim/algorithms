#include<bits/stdc++.h>
using namespace std;
int cnt,n;
int dp[45];
int main(){
	int i,j;
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=2;
	for(i=4;i<45;i++)
	dp[i]=dp[i-1]+dp[i-2];
	scanf("%d",&n);
		while(n--){
			scanf("%d",&n);
				cout<<dp[n]<<endl;		 
		
	}
}

