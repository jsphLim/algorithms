#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=10000+5;
const int inf=99999999;
int dis[maxn];
int n,m;
int map[maxn][maxn];
int vis[maxn];
void dijkstra(int st,int en){
	memset(vis,0,sizeof(vis));
	vis[st]=1;
	for(int i=1;i<=n;i++) dis[i]=map[st][i];
	int minn=inf,pos;
	for(int i=1;i<=n;i++){
		minn=inf;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				pos=j;
				minn=dis[j];
			}
		}
		vis[pos]=1;
		for(int j=1;j<=n;j++){
			if(dis[j]>dis[pos]+map[pos][j]) dis[j]=dis[pos]+map[pos][j];
		}
	}
}
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) map[i][j]=(i==j?1:inf);
}
int main(){
	int t,a[maxn],b[maxn],c[maxn];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			map[a[i]][b[i]]=c[i];
		}
		long long sum=0;
		dijkstra(1,n);
		for(int i=2;i<=n;i++)  sum+=dis[i];
		init();
		for(int i=1;i<=m;i++){
			map[b[i]][a[i]]=c[i];
		}
		dijkstra(1,n);
		for(int i=2;i<=n;i++) sum+=dis[i];
		cout<<sum<<endl;
	}
}
