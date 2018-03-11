#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int inf=999999;
int dis[1055];
int vis[1055];
int mp[1055][1555];
int n,m;
void dijkstra(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=mp[1][i];
	int minn,pos;
	for(int i=1;i<=n;i++){
	    minn=-888;
	    for(int j=1;j<=n;j++){
	    	if(!vis[j]&&dis[j]>minn){
	    		pos=j;
	    		minn=dis[j];
			}
		}
		vis[pos]=1;
		for(int j=1;j<=n;j++){
		 if(!vis[j]) dis[j]=max(dis[j],min(dis[pos],mp[pos][j]));
		}
	}
} 
int main(){
	int t,kcase=1;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		memset(mp,0,sizeof(mp));
		   int a,b,c;
		   while(m--){
		   	scanf("%d%d%d",&a,&b,&c);
		   	 mp[a][b]=mp[b][a]=c;
		   }
		   dijkstra();
		   printf("Scenario #%d:\n",kcase++);
		   cout<<dis[n]<<endl<<endl;
	}
}
