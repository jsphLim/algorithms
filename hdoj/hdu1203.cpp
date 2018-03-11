#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	double y;
};
bool cmp(node x,node y){
	if(x.x*y.y==y.x*x.y) return x.x<y.x;
	return x.x*y.y<y.x*x.y;
}
int main(){
	int n,m;
	node ans[10050];
	double sum;
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		sum=1;
		for(int i=0;i<m;i++) scanf("%d%lf",&ans[i].x,&ans[i].y);
		sort(ans,ans+n,cmp);
		for(int i=0;i<n;i++){
			if(n-ans[i].x){
				n-=ans[i].x;
				sum*=(1-ans[i].y);
			}
		}
		sum=1-sum;
		sum=sum*100;
		printf("%.1f%\n",sum);
	}
}
