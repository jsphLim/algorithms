#include<bits/stdc++.h>
using namespace std;
int mp[1000][1000];
int n;
int cnt,sum;
void dfs(int i,int j,int cnt){
	if(i==n){
		if(cnt%3==0)
		sum++;return ;
	}
	if(j==1){
		dfs(i+1,j,cnt+mp[i+1][j]);
		dfs(i+1,j+1,cnt+mp[i+1][j+1]);
	}
	else if(j==n){
			dfs(i+1,j,cnt+mp[i+1][j]);
			dfs(i+1,j-1,cnt+mp[i+1][j-1]);
	}
	else{
	     	dfs(i+1,j,cnt+mp[i+1][j]);
	     	dfs(i+1,j-1,cnt+mp[i+1][j-1]);
	     	dfs(i+1,j+1,cnt+mp[i+1][j+1]);
	}
	
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=n;j++){
		   	scanf("%d",&mp[i][j]);
		   }
		   sum=0;
		   for(int i=1;i<=n;i++)
		   dfs(1,i,mp[1][i]);
		   cout<<sum<<endl;
	}
}
