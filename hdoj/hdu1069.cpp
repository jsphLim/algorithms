#include<bits/stdc++.h>
using namespace std;
struct node{
	int lon;
	int breath;
	int high;
}ans[100005];
bool cmp(node x,node y){
	if(x.breath==y.breath) return x.lon<y.lon;
	return x.breath<y.breath;
}
int dp[100005],kase=1;
int main(){
	int n;
	int ad[3];
	int k=0;
	while(cin>>n,n){
		k=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ad[0],&ad[1],&ad[2]);
			sort(ad,ad+3);
			ans[k].breath=ad[2];
			ans[k].lon=ad[0];
			ans[k].high=ad[1];
			k++;
			ans[k].breath=ad[1];
			ans[k].lon=ad[0];
			ans[k].high=ad[2];
			k++;
			ans[k].breath=ad[2];
			ans[k].lon=ad[1];
			ans[k].high=ad[0];
			k++;
		}
		sort(ans,ans+k,cmp);
	   for(int i=0;i<k;i++) dp[i]=ans[i].high;
	   
		for(int i=0;i<k;i++){
			for(int j=0;j<i;j++){
				if((ans[i].breath>ans[j].breath&&ans[i].lon>ans[j].lon)) dp[i]=max(dp[i],dp[j]+ans[i].high);
	}
	}
	int maxx=-1;
	for(int i=0;i<=k;i++)
	if(maxx<dp[i]) maxx=dp[i];
	printf("Case %d: maximum height = %d\n",kase++,maxx);
}
}
	 

