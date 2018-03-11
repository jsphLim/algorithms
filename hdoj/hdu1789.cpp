#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int deal[105];
int score[105];
int vis[105];
int main(){
	int t,i,j,m,n;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&deal[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&score[i]);
		}
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			if(score[i]<score[j]){
				swap(deal[i],deal[j]);
				swap(score[i],score[j]);
			}
			else if(score[i]==score[j]){
				if(deal[i]>deal[j]) swap(deal[i],deal[j]);
			}
		}
		memset(vis,0,sizeof(vis));
		int ans=0;
	    for(i=1;i<=n;i++){
	    	for(j=deal[i];j>=0;j--)
	    	{
				if(vis[j]==0){
					vis[j]=1;
					break;
				}
				else ans++;
			}
			
		}
       cout<<ans<<endl;
   }
}
