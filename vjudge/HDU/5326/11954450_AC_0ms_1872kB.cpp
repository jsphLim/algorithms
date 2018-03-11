#include<bits/stdc++.h>
using namespace std;
vector<int> g[5000];
int cnt[5000];
int dfs(int u){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
	    dfs(v);
	    cnt[u]+=cnt[v];
	}
}
			
int main(){
	 int n,k,u,v;
	 while(cin>>n>>k){
	 	for(int i=0;i<n-1;i++){
	 		scanf("%d%d",&u,&v);
	 		g[u].push_back(v);
	 	}
	 	memset(cnt,0,sizeof(cnt));
	 	for(int i=1;i<=n;i++){
	 		cnt[i]=g[i].size();
	 	}
	 	dfs(1);
	 	int sum=0;
	 	for(int i=1;i<=n;i++){
	 		if(cnt[i]==k) sum++;
	 	}
	 	cout<<sum<<endl;
	 	for(int i=1;i<=n;i++) g[i].clear();
	 }
}
	 	