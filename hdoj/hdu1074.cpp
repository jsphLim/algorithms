#include<bits/stdc++.h>
using namespace std;
struct node{
	char s[10];
	int a;
	int b;
};
int vis[1000];
bool cmp(node x,node y){
	if(x.b==y.b) return x.a<y.a;
	return x.b>y.b;
}
int main()
{
	int  t,n,i,k,j;
	node a[1000];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s %d%d",&a[i].s,&a[i].a,&a[i].b);
		}
		sort(a,a+n,cmp);
			memset(vis,0,sizeof(vis));
		int ans=0;
	    for(i=0;i<n;i++){
	    	for(j=a[i].a;j>=0;j--)
	    	{
				if(vis[j]==0){
					vis[j]=1;
				 break;
				}
			}
				if(j<=1) ans+=abs(j);
		}
       cout<<ans<<endl;
	}
} 
