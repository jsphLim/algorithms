#include<bits/stdc++.h>  //万能头文件  
using namespace std;  

int a[35][35];
int flag;
int t,n,m;

void bian(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(j==i) continue;
			if(a[1][j]==a[1][i]){
				flag=1;return;
			}
			if(a[n][j]==a[n][i]){	
				flag=1;return;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(a[j][1]==a[i][1]){
				flag=1;return;
			}
			if(a[j][m]==a[i][m]){
				flag=1;return;
			}
		}
	}
}

void neibu(){
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			if(a[i][j]==a[i-1][j]||a[i][j]==a[i+1][j]||a[i][j]==a[i][j-1]||a[i][j]==a[i][j+1]){
				flag=1;return;
			}
		}
	}
	
}

int main(){
	
	int cnt=1;
	cin>>t;
	while(t--){
		flag=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		bian();
		neibu();
		printf("Case #%d: ",cnt++);
		if(flag) cout<<"Yes"<<endl;
		if(!flag) cout<<"No"<<endl;
	}
} 
