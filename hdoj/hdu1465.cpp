#include<bits/stdc++.h>
using namespace std;
long long f[25]={1,0,1,2};
void init(){
	for(int i=4;i<=25;i++) f[i]=(i-1)*(f[i-1]+f[i-2]);
}
 int main(){
 	int n;
 	init();
 	while(scanf("%d",&n)!=EOF){
 		long long sum=0;
 		if(n==1||n==2) cout<<1<<endl;
 		else{
 			cout<<f[n]<<endl;
		 }
		 
	 }
 }
