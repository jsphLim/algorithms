#include<bits/stdc++.h>
using namespace std;
int ans[1005];
int main(){
	int n,m;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++) scanf("%d",&ans[i]);
		int sum=0;
		sort(ans,ans+n);
		for(int i=0;i<n;i++)
		    for(int j=i+1;j<n;j++){
		    	if(ans[j]>ans[i]) sum=sum+ans[j]-ans[i];
			}
			cout<<sum<<endl;
	}
} 
