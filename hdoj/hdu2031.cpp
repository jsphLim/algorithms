#include<bits/stdc++.h>
using namespace std;
    int n;
	int a[100];
	int i,m;
void zz(int x){
	int j=0;
	while(x){
			a[j++]=x%m;
			x/=m;
}
}
int main(){
	int flag=0;
	
	while(scanf("%d%d",&n,&m)!=EOF){
		flag=0;
		memset(a,0,sizeof(a));
		if(n<0){
			flag=1;
			n=-n;
		}
		zz(n);
		int u=35;
		while(a[u]==0) u--;
		if(flag==1) cout<<"-";
		for(int i=u;i>=0;i--){
		if(a[i]<10) cout<<a[i];
		 else cout<<a[i]-10+'A';
		}
		cout<<endl;
	}
}
