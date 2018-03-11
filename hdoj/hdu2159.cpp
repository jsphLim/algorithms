#include<bits/stdc++.h>
using namespace std;
int v[1000];
int w[1000];
int dp[1000][1000];
int main(){
	int n,m,k,s,j;
	while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
		for(int i=0;i<k;i++) scanf("%d%d",&v[i],&w[i]);
		
		memset(dp,0,sizeof(dp));
		for(int i=0;i<k;i++)
		  for(int p=1;p<=s;p++)
		  for(j=m;j>=w[i];j--){
		  	dp[p][j]=max(dp[p][j],dp[p-1][j-w[i]]+v[i]);
		  }
		  
		  if(dp[s][m]<n) cout<<-1<<endl;
		  else{
		for(j=1;j<=m;j++)
            if(dp[s][j]>=n)
                break;
                cout<<m-j<<endl;
		  }
	}
} 
