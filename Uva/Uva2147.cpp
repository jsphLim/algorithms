#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int map[10][10];
int to[4][2]={1,0,-1,0,0,1,0,-1};
int vis[10][10];
int vis2[10][10];
int sx,sy,ex,ey;
int n,m;
struct node{
	int x;
	int y;
	int step;
};
bool checkPeople(int x,int y){
	if(x<0||x>=n||y<0||y>=m||map[x][y]==1) return false;
	return true;
}
bool dfs(int x,int y,int x1,int y1){
	if(x==x1&&y==y1) return true;
	for(int k=0;k<4;k++){
		int xx=x+to[k][0];
		int yy=y+to[k][1];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&map[xx][yy]!=1&&map[xx][yy]!=2&&vis2[xx][yy]==0){
			vis2[xx][yy]=1;
			dfs(xx,yy,x1,y1);
		} 
	}
	return false;
}
int bfs(node x){
	queue<node> que;
	memset(vis,0,sizeof(vis));
	int steps=0;
	que.push(x);
	while(!que.empty()){
		node first=que.front();
		que.pop();
		if(map[first.x][first.y]==3) break;
		if(vis[first.x][first.y]) continue;
		steps=first.step;
		for(int k=0;k<4;k++){
			memset(vis2,0,sizeof(vis2));
			if(k==0&&!checkPeople(first.x-1,first.y))  continue;
			if(k==1&&!checkPeople(first.x+1,first.y))  continue;
			if(k==2&&!checkPeople(first.x,first.y-1))  continue;
			if(k==3&&!checkPeople(first.x-1,first.y+1))  continue;
			if(!dfs(sx,sy,first.x-to[k][0],first.y-to[k][1])) continue;
			int x1=first.x+to[k][0];
			int y1=first.y+to[k][1];
			
			if(map[x1][y1]==1||vis[x1][y1]==1) continue;
			vis[x1][y1]=1;
			sx=x1-to[k][0];
			sy=y1-to[k][1];
			node next;
			next.x=x1;
			next.y=y1;
			next.step=first.step+1;
			printf("%d%d%d\n",next.x,next.y,next.step);
			que.push(next);
			//cout<<"test"<<endl;
		}
	}	
	return steps;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==4){
					sx=i;
					sy=j;
				}
			}
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(map[i][j]==2){
					node fr;
					fr.x=i;
					fr.y=j;
					fr.step=0;
					int ans=bfs(fr);
					printf("%d\n",ans);
				}
			}
	}
}
