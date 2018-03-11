#include<bits/stdc++.h>
using namespace std;
int prim[8000];
int u=0;
int c1[205],c2[205]; 
void isprim(int x){
	if(x==2) {prim[u++]=x; return ;}
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return ;
	}
	prim[u++]=x;
}
int main(){
	for(int i=2;i<=200;i++) isprim(i);
	for(int i=0;i<=200;i+=2){
		c1[i]=1;
	}
	memset(c2,0,sizeof(c2));
	for(int i=0;i<=160;i++){
		for(int j=0;j<=160;j++){
			for(int k=0;k+j<=160;k+=prim[i]){
			c2[j+k]+=c1[j];
			}
		}
		for(int j=0;j<=200;j++){
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	 int t,n;
	 cin>>t;
	 while(t--){
	 	scanf("%d",&n);
	 	cout<<c1[n]<<endl;
	 }
}
