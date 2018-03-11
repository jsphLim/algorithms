#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int vis[1000][1000];
int main(){
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) {
		scanf("%d",&a[i][j]);
		if(a[i][j]<0){
			a[i][j]=-a[i][j];
			vis[i][j]=1;	
		} 
		}
		int x,y;
		int maxx=-1;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(a[i][j]>maxx){
				maxx=a[i][j];
				x=i;
				y=j;
			}
			if(a[i][j]==maxx){
				continue;
			}
		}
		if(vis[x][y]==1) maxx=-maxx;
		cout<<x<<" "<<y<<" "<<maxx<<endl;
	}
}
