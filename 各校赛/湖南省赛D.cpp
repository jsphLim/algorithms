#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[200][200];
int vis[200];
int match[200];
int matches(int u){
	int i;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&mp[u][i]==1){
			vis[i]=1;
			if(match[i]==0||matches(match[i])){
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int hun(){
	int sum=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(matches(i)) sum++;
	}
	return sum;
}

int main(){
	int a,b;
	while(~scanf("%d%d",&n,&m)){
		while(m--){
			scanf("%d%d",&a,&b);
			mp[a][b]=1;
		}
		cout<<hun()<<endl;
	}
}
