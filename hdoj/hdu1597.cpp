#include<bits/stdc++.h>
using namespace std;
long long biao[50005];
int main(){
	biao[0]=0;
	for(int i=1;i<=50000;i++){
	biao[i]=(ceil)(i+1)*i/2;}
	long long n,t;
	cin>>t;
	while(t--){
		scanf("%I64d",&n);
		int vis,v;
		for(int i=0;i<50000;i++){
			if(biao[i]<n&&n<=biao[i+1]){
				vis=biao[i];
				break;
			}
		}
		if((n-vis)%9==0) cout<<9<<endl;
		else
		cout<<(n-vis)%9<<endl;
	}
}
			
