#include<iostream>
#include<string.h>
using namespace std;
int cpp[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char ss[40][40];
int m,n,cnt;
void dfs(int i,int j){
	ss[i][j]='#';
	cnt++;
	for(int k=0;k<4;k++){
		int x=i+cpp[k][0];
		int y=j+cpp[k][1];
		if(x>=0&&y>=0&&x<n&&y<m&&ss[x][y]=='.'){
			dfs(x,y);
		}
	}
} 
int main(){
	int i,j,x1,y1;
	while(scanf("%d%d",&m,&n)){
		getchar();
		 if(m == 0 && n == 0)  
            break;
            memset(ss,0,sizeof(ss));
		for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%c",&ss[i][j]);
			if(ss[i][j]=='@'){
				x1=i;
				y1=j;
			}
		}
		getchar();
	}
		cnt=0;
		dfs(x1,y1);
		cout<<cnt<<endl;
	}
}
