#include<bits/stdc++.h>
using namespace std;
int n,k;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mp[1000][1000];
int ans=0;
int dp[1000][1000];
int dfs(int x,int y){
	if(dp[x][y]) return dp[x][y];
    int sum=0;
	for(int i=0;i<4;i++){
		for(int j=1;j<=k;j++){
			int x1=x+j*dir[i][0];
			int y1=y+j*dir[i][1];	
			if(x1>=n||y1>=n||x1<0||y1<0) break;
			else if(mp[x1][y1]>mp[x][y]){			
			sum=max(sum,dfs(x1,y1));
			}	
		}
	}
     return dp[x][y]=sum+mp[x][y];
}
int main(){
	while(scanf("%d%d",&n,&k)){
		if(n==-1&&k==-1) break;
		for(int i=0;i<n;i++)
		    for(int j=0;j<n;j++) scanf("%d",&mp[i][j]);
		    memset(dp,0,sizeof(dp));
		    cout<<dfs(0,0)<<endl;
	}
}
