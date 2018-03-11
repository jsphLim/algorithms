#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int step[1000000];
int vis[1000000];
queue<int> q;
int bfs(int x,int y){
	int first,next;
	q.push(x);
	step[x]=0;
	vis[x]=1;
	while(!q.empty()){
		first=q.front();
		q.pop();
		for(int i=0;i<3;i++){
			if(i==0) next=first+1;
			if(i==1) next=first-1;
			if(i==2) next=2*first;
			if(next<0) continue;
			if(!vis[next]){
				vis[next]=1;
				q.push(next);
				step[next]=step[first]+1;
			} 
			if(next==y) return step[next];
		}
	}
	while(!q.empty()) q.pop();
}
int main(){
     int n,m;
	    scanf("%d%d",&n,&m);
	 	if(n>=m) printf("%d\n",n-m);
	 	else {
	 		printf("%d\n",bfs(n,m));
		 }
}
