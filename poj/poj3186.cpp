#include<bits/stdc++.h>
using namespace std;
int ans[10000];
int maxx[3005][3005];	
int t;
int dfs(int st,int en){
	if(maxx[st][en]!=0) return maxx[st][en];
	if(st==en) return maxx[st][st]=t*ans[st];
	int x=dfs(st+1,en)+(t-en+st)*ans[st];
	int y=dfs(st,en-1)+(t-en+st)*ans[en];
	maxx[st][en]=max(x,y);
	return maxx[st][en];
}
int main(){

    while(cin>>t){
    	memset(maxx,0,sizeof(maxx));
    	for(int i=1;i<=t;i++) scanf("%d",&ans[i]);
		cout<<dfs(1,t)<<endl;
	}
}
