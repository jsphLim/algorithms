#include<bits/stdc++.h>  //万能头文件  
#define LL long long 
using namespace std;  
int n,m,k;
int ci[30];
int mapi[6][6];
bool flag;
void dfs(int r,int c){
//	if(flag) return;
	if(r==n+1&&c==1){
		flag=true;
		return;
	} 
	for(int i=1;i<=k;i++){
			if(ci[i]>((n-r)*(m-c)+1)/2) return ;
	} 
	for(int i=1;i<=k;i++){
		if(!ci[i]) continue;
		if(mapi[r][c-1]==i||mapi[r-1][c]==i) continue;
		ci[i]--;
		mapi[r][c]=i;
		if(c<m){
			dfs(r,c+1);
		}
		else dfs(r+1,1);
		if(flag) return; 
		ci[i]++;
//		mapi[r][c]=0;
		
	}
	return;
}

int main(){
	int t;
	int cnt=1;
	scanf("%d",&t);
	while(t--){
		bool flag1=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++){
			scanf("%d",&ci[i]);
			if(ci[i]>(n*m+1)/2) flag1=true;
		} 
		if(flag1) {
			printf("Case #%d:\nNO\n",cnt++);  
            continue; 
		}

		flag=false;
		dfs(1,1);
		printf("Case #%d:\n",cnt++);
		if(flag==false) printf("NO\n");
		else {
			printf("YES\n");
			for(int i=1;i<=n;i++){
				for(int j=1;j<m;j++){
					printf("%d ",mapi[i][j]);
				}
				printf("%d\n",mapi[i][m]);
			}
		}
	}
	
}

