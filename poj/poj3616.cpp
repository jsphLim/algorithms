#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int st;
	int en;
	int co;
};
int dp[1050];
bool cmp(node x,node y){
     return x.en<y.en;
}
int main(){
	node ans[10000];
	int n,m,r;
	while(cin>>n>>m>>r){
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&ans[i].st,&ans[i].en,&ans[i].co);
			ans[i].en+=r;
		} 
		int stx,enx;
		memset(dp,0,sizeof(dp));
		sort(ans,ans+m,cmp);
        for(int i=0;i<m;i++){
        	dp[i]=ans[i].co;
        	for(int j=0;j<i;j++){
        		if(ans[j].en<=ans[i].st){
        			dp[i]=max(dp[i],dp[j]+ans[i].co);
				}
			}
		}
		cout<<*max_element(dp, dp + m)<<endl;		
	}
}
