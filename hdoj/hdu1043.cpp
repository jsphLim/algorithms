#include<bits/stdc++.h>
using namespace std;
int vis[100];
char mp[12];
char mpx[4][4];
int zou[4][2]={1,0,-1,0,0,1,0,-1}
int dr,flag;
void dfs(int x,int y,int dr){
	if(strcmp(mpx[0],"123")==0&&strcmp(mpx[1],"456")&&strcmp(mpx[2],"78x")) {
		flag=1;
		cnt=dr;
	}
	if(flag) return ;
	for(int k=0;k<4;k++){
		int xx=x+zou[k][0];
		int yy=y+zou[k][1];
		if(xx<3&&yy<3&&x>=0&&yy>=0){
			swap(mpx[xx],mpx[x]);
			swap(mpx[yy],mpx[y]);
			vis[dr]=k;
			dfs(xx,yy,dr+1);
			swap(mpx[xx],mpx[x]);
			swap(mpx[yy],mpx[y]);
		}
	}
}
int main(){
	while(scanf("%s",mp)!=EOF){
		for(i=0;i<9;i++){
			if(mp[i]=='x')
			break;
		}
		int x,y;
		x=i/3;
		y=i%3;
		int k=0;
		for(i=0;i<3;i++)
		for(j=0;j<3;j++){
			mpx[i][j]=mp[k++];
		}
		flag=0;
		cnt=0;
		dfs(x,y,0);
		for(i=0;i<cnt;i++){
			if(vis[i]==0) cout<<"d";
			if(vis[i]==1) cout<<"u";
			if(vis[i]==2) cout<<"r";
			if(vis[i]==3) cout<<"l";
		}
	}
}
