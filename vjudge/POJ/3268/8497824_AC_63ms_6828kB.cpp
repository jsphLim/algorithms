#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int inf=999999;
int dis[1055];
int vis[1055];
int mp[1055][1555];
int n,m;
int arr[1055]={0};
void dijkstra(int bg,int en){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=mp[bg][i];
	int minn,pos;
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
		 if(!vis[j]) dis[j]=min(dis[j],dis[pos]+mp[pos][j]);
		}
	}
	for(int i=1;i<=n;i++){
	
		   		arr[i]+=dis[i];
	}
} 
int main(){
           int x;
		scanf("%d%d%d",&n,&m,&x);
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++){
		    if(i==j) mp[i][j]=0;
		    else mp[i][j]=inf;
		}
		    memset(arr,0,sizeof(arr));
		   int a,b,c;
		   while(m--){
		   	scanf("%d%d%d",&a,&b,&c);
		   	 mp[a][b]=c;
		   }
		   dijkstra(x,n);
		   for(int i=1;i<n;i++)
		       for(int j=i+1;j<=n;j++) swap(mp[i][j],mp[j][i]);
		       dijkstra(x,n);
		       int sum=0;
		   for(int i=1;i<=n;i++)  sum=max(sum,arr[i]);
		   cout<<sum<<endl; 
}