#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
char map[150][150];
int vis[150][150];
int cnt,n,m,ans;
const int inf=999999999;
struct node{
	int x;
	int y;
	int step;
};
bool check(int x,int y){
	if(x<0||x>=n||y<0||y>=m||vis[x][y]==1||map[x][y]!='#') return false;
	return true;
}
bool checkAll(){
	for(int i=0;i<n;i++)
	   for(int j=0;j<m;j++){
	   	if(map[i][j]=='#'&&vis[i][j]==0) return false;
	   } 
	   return true;
}
int bfs(node a,node b){
	queue<node> que;
	memset(vis,0,sizeof(vis));
	que.push(a);
	que.push(b);
	int steps=0;

	while(!que.empty()){
		node p=que.front();
		que.pop();
		if(vis[p.x][p.y]) continue;
		 vis[p.x][p.y]=1;
		 steps=p.step;
		 if(check(p.x+1,p.y)){
		 	node next=p;
		 	next.step++;
		 	next.x++;
		 	que.push(next);
		 }
		 if(check(p.x,p.y+1)){
		 	node next=p;
		 	next.step++;
		 	next.y++;
		 	que.push(next);
		 }
		 if(check(p.x-1,p.y)){
		 	node next=p;
		 	next.step++;
		 	next.x--;
		 	que.push(next);
		 }
		 if(check(p.x,p.y-1)){
		 	node next=p;
		 	next.step++;
		 	next.y--;
		 	que.push(next);
		 }
	}
	return steps;
}
int main(){
	int ans=inf;
	int t,kase=1;
	cin>>t;
	vector<node> collect;
	while(t--){
		ans=inf;
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		collect.clear();
		for(int i=0;i<n;i++)
			scanf("%s",&map[i]);
			
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(map[i][j]=='#'){
					node c;
					c.x=i;
					c.y=j;
					c.step=0;
					collect.push_back(c);
				}
			}
		for(int i=0;i<collect.size();i++)
			for(int j=i;j<collect.size();j++){
				collect[i].step=collect[j].step=0;
				int aos=bfs(collect[i],collect[j]);
				if(checkAll()) ans=min(ans,aos);
			}
			if(ans==inf) printf("Case %d: %d\n",kase++,-1);
			else printf("Case %d: %d\n",kase++,ans);
	}
	
}