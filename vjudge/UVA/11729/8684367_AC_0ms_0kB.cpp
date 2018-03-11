#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 20005;
struct node{
	int x,y;
}ans[maxn];
bool cmp(node x,node y){
	return x.y>y.y;
}
int main(){
	int n,kase=1;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++) scanf("%d%d",&ans[i].x,&ans[i].y);
		sort(ans,ans+n,cmp);
		int sum=0,cnt=0;
		for(int i=0;i<n;i++){
			sum+=ans[i].x;
			cnt=max(cnt,sum+ans[i].y);
		}
		cout<<"Case "<<kase++<<": ";
		cout<<cnt<<endl;
	}
}