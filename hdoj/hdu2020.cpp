#include<bits/stdc++.h>
using namespace std;
int flag=-99999999;
int vis[105];
int a[105];
bool cmp(int x,int y){
	return  abs(x)>abs(y);
} 
int main(){
	int n,i;
	while(cin>>n){
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		for(i=0;i<n-1;i++){
			if(a[i]!=flag) cout<<a[i]<<" ";
			flag=a[i];
		}
		if(i==n-1&&a[i]!=flag) cout<<a[i]<<endl;
	}
}
