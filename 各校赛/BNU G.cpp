#include<bits/stdc++.h>
using namespace std;
long long ans[1000000][1000000];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%I64d",&ans[i]);
	   int flag=0,maxx=0;
//	   for(int i=1;i<=n;i++){
//			for(int j=n;j>i;j--){
//				if(ans[i]<=ans[j]){
//					maxx=max(maxx,j-i);
//				}
//			}
//		}
		for(int len=n-1;len>=1;len--){
			for(int i=1;i+len<=n;i++){
				if(ans[i]<=ans[i+len]){
					maxx=len;flag=1;break;
				}
			}
			if(flag)break;
		}
			cout<<maxx<<endl;
		}
	}
