#include<bits/stdc++.h>
using namespace std;
char cbegin[10000];
char cend[10000];
char cun[10000];
int vis[10005]={0};
int k,m,flag;
char re(){
	for(int i=0;;i++){
		if(cun[i]==0){
			return cun[i-1];
		}
	}
}
void dfs(char x){
	if(x=='m') flag=1;
	if(flag) return ;
	for(int i=0;i<k;i++){
		if(vis[i]==1) continue;
		if(x==cbegin[i]){
			
			vis[i]=1;
			dfs(cend[i]);
			vis[i]=0;
		}
	}
}
int main(){
	k=0,m=0;
	while(scanf("%s",cun)){
		if(strcmp(cun,"0")!=0){
		cbegin[k++]=cun[0];
		cend[m++]=re();
		memset(cun,0,sizeof(cun));
	}
	else{
	flag=0;
	for(int i=0;i<k;i++){
		if(flag) break;
		if(cbegin[i]=='b'){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(cend[i]);
		}
	}
	if(flag==1) cout<<"Yes."<<endl;
	else cout<<"No."<<endl; 
	m=k=0;
	memset(cend,0,sizeof(cend));
	memset(cbegin,0,sizeof(cbegin));
}
}
}
