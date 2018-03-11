#include<bits/stdc++.h>
using namespace std;
int vis[4];
int main(){
	int n,m,i,temp;
	scanf("%d",&n);
		scanf("%d",&m);
		memset(vis,0,sizeof(vis));
		vis[m]=1;
		n=n%6;
		for(i=n;i>=1;i--){
			if(i%2){
			if(vis[0]==0&&vis[1]==0) continue;
		    temp=vis[0];
			vis[0]=vis[1];
			vis[1]=temp;
			}
			else{
			if(vis[1]==0&&vis[2]==0) continue;
			temp=vis[1];
			vis[1]=vis[2];
			vis[2]=temp;
			}
		}
		
		for(i=0;i<3;i++) if(vis[i]==1) {
		printf("%d\n",i);
		break;		
   	}
}
