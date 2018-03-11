#include<bits/stdc++.h>
using namespace std;
float ans[10050];
float cost[10050];
int v[10050];
float max(float a,float b){
	return a>b?a:b;
}
int main(){
	int n,i,j;
	float sum,m;
	int t;
	scanf("%d",&t);
	while(t--){
		int mon=0;
	    scanf("%f%d",&sum,&n);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++) {
		scanf("%d%f",&v[i],&cost[i]);
		mon+=v[i];	
		cost[i]=(1.0-cost[i]);
		}
		ans[0]=1.0;
	    for(int i=1;i<=n;i++)
		   for(int j=mon;j>=v[i];j--){
		   	   ans[j]=max(ans[j],ans[j-v[i]]*cost[i]);
		   } 
		   for(int i=mon;i>=0;i--)
		   if(ans[i]+sum>=1){
	        printf("%d\n",i);
	        break;
	    }
}
}
