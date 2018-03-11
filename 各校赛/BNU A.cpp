#include<bits/stdc++.h>
using namespace std;
int liu[50000];
int main(){
	 int n,t;
	 cin>>t;
	 while(t--){
	 	scanf("%d",&n);
	 	for(int i=1;i<=2*n-2;i++) scanf("%d",&liu[i]);
	 	int ans=11111111;
	 	for(int i=1;i<2*n-2;i+=2){
	 	    ans=min(ans,liu[i]+liu[i+1]);
	 	}
	 	cout<<ans<<endl;
	 }
}
