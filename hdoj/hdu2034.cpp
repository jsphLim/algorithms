#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],c[105];
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		int flag,k=0;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		for(int i=0;i<n;i++){
		flag=0;
		for(int j=0;j<m;j++){
			if(a[i]==b[j]) break;
			else if(j==m-1) c[k++]=a[i];
		}
	}

		if(k==0) cout<<"NULL"<<endl;
		else{
			sort(c,c+k);
			for(int i=0;i<k;i++) cout<<c[i]<<" ";
			cout<<endl;
		}
		memset(c,0,sizeof(c));
	}
}
