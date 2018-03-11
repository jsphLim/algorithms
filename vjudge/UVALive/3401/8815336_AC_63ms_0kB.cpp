#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn=6;

int n,ans,dice[maxn][6];//dice记录初始的情况 

int dice24[][6]={{2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},
{4,2,5,0,3,1},{5,2,1,4,3,0},{1,2,0,5,3,4},{0,2,4,1,3,5},{0,1,2,3,4,5},{4,0,2,3,5,1},{5,4,2,3,1,0},{1,5,2,3,0,4},
{5,1,3,2,4,0},{1,0,3,2,5,4},{0,4,3,2,1,5},{4,5,3,2,0,1},{3,4,5,0,1,2},{3,5,1,4,0,2},{3,1,0,5,4,2},{3,0,4,1,5,2},
{1,3,5,0,2,4},{0,3,1,4,2,5},{4,3,0,5,2,1},{5,3,4,1,2,0},
};

vector<string> names;

int ID(const char* name){
	string s(name);
	int n=names.size();
	for(int i=0;i<n;++i){
		if(s==names[i])return i;
	}
	names.push_back(s);
	return n;
}

int color[maxn][6];
int r[maxn];//记录第r种旋转 

void check(){
	for(int i=0;i<n;++i){//第二次把这里的i从1开始计的，导致第一个正方体所有的值都是0 
		for(int j=0;j<6;++j){
			color[i][dice24[r[i]][j]]=dice[i][j];
		}
	}
//	for(int i=0;i<n;++i){
//		for(int j=0;j<6;++j){
//			cout<<color[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	int tmp=0;
	for(int i=0;i<6;++i){
		int cnt[6*maxn];
		memset(cnt,0,sizeof(cnt));
		int maxcolor=0;
		for(int j=0;j<n;++j){
			maxcolor=max(maxcolor,++cnt[color[j][i]]);//第一次把这俩打反了，找了半天 
		}
		tmp+=n-maxcolor;
	}
//	cout<<tmp<<endl;
	ans=min(ans,tmp);
}

void dfs(int d){
	if(d==n)check();
	else {
		for(int i=0;i<24;++i){
			r[d]=i;
			dfs(d+1);
		}
	}
}

int main(){
	while(scanf("%d",&n)&&n){
		names.clear();
		for(int i=0;i<n;++i){
			for(int j=0;j<6;++j){
				char name[30];
				scanf("%s",name);
				dice[i][j]=ID(name);
			}
		}
		ans=36;
		r[0]=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}