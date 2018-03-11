/*************************************************************************
	> File Name: POJ-2386.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月06日 星期二 15时34分23秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
char map[105][105];
bool vis[105][105];
int to[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int m,n;

void dfs(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<8;i++){
        int xto = x+to[i][0];
        int yto = y+to[i][1];
        if(xto<0||xto>=n||yto<0||yto>=m) continue;
        if(!vis[xto][yto]&&map[xto][yto]=='W') dfs(xto,yto);
    }

}


int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("poj-2386_data.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
        }
        memset(vis,false,sizeof(vis));
        int cnt=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&map[i][j]=='W') {cnt++; dfs(i,j); }
        } 

        printf("%d\n",cnt);
    }    

}