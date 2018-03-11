#include<bits/stdc++.h>
using namespace std;
char a[10][10]={0};
int zou[4][2]={1,0,0,1,-1,0,0,-1};
int cnt,n;
bool check(int x,int y){
	int x1,y1;
	for(int i=0;i<4;i++)
	{
		x1=x+zou[i][0];
		y1=y+zou[i][1];
		while(x1>=0&&x1<n&&y1>=0&&y1<n&&a[x1][y1]!='X')
		{
		    if(a[x1][y1]=='@')
				return false;
			x1+=zou[i][0];y1+=zou[i][1];
		}
	}
	return true;
}
void dfs(int x){
	if(x>cnt) cnt=x;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='.'&&check(i,j)){
				a[i][j]='@';
				dfs(x+1);
				a[i][j]='.';
			}
		}
	}
}
int main(){
	while(scanf("%d ",&n),n){
	for(int i=0;i<n;i++)
    gets(a[i]);
	cnt=0;
	dfs(0);
	cout<<cnt<<endl;
}
}
