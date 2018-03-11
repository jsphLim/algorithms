#include<bits/stdc++.h>
using namespace std;
 int n,m,bu;
 int xq,yq,xm,ym;
 int i,j,kk;
 int cnt,flag;
 int zou[4][2]={0,1,1,0,0,-1,-1,0};
 char map1[10][10];
void dfs(int x,int y,int t){
	if(x>=n||y>=m||x<0||y<0) return ;
	if(t==bu&&x==xm&&y==ym) {
		flag=1;
	}
	if(flag) return;
	if(((bu-t)%2 != (abs(x-xm) + abs(y-ym)) %2)) return;
	for(int k=0;k<4;k++){
		int x2=x+zou[k][0];
		int y2=y+zou[k][1];
		
		if(map1[x2][y2]!='X'){
			map1[x2][y2]='X';
			dfs(x2,y2,t+1);
			map1[x2][y2]='.';
		}
	}
	return ;
}
int main(){
	
    while(scanf("%d%d%d",&n,&m,&bu)){
    	int wall=0;
    	if(n==0||m==0||bu==0) break;
          getchar();
    	for(i=0;i<n;i++)
    	for(j=0;j<m;j++){
    		scanf(" %c",&map1[i][j]);
    		if(map1[i][j]=='S'){
    			xq=i;yq=j;
			}
			if(map1[i][j]=='D'){
				xm=i;
				ym=j;
			}
			if(map1[i][j]=='X') wall++;
		} 
		flag=0;
		cnt=0;
		
		map1[xq][yq]='X';
		dfs(xq,yq,0);
    	if(flag) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
	}

}
