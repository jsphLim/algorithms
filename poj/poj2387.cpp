#include<iostream>
#include<cstring>
using namespace std;
int dis[5000];
int mp[5005][5005];
int vis[5005];
int n;
const int inf=10000005;
void dij(){
	int i,j;
	for(i=0;i<=n;i++) dis[i]=mp[1][i];
	memset(vis,0,sizeof(vis));
	int pos,minn;
	for(i=1;i<=n;i++){
		minn=inf;
		for(j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				minn=dis[j];
				pos=j;
			}
	    }
			vis[pos]=1;
		for(j=1;j<=n;j++){
			if(dis[j]>dis[pos]+mp[pos][j]) dis[j]=dis[pos]+mp[pos][j];
		}
	}
}
int main(){
	int t;
	while(cin>>t>>n){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
              mp[i][j]=inf;
			}
		}
		int a,b,c;
		for(int i=1;i<=t;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(mp[a][b]>c) mp[a][b]=mp[b][a]=c;
		}
		dij();
		cout<<dis[n]<<endl;
	}
	
}
