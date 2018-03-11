#include<bits/stdc++.h>
using namespace std;
int tree[1000000];
int temp[1000000];
int vis[100000];
int vs[1000000];
int sum=0;
int summain=0;
int flag=0;
void f(int x){
	if(x==0){
		temp[x]=summain;
		flag=1;
	} 
	if(flag==1)
		return;
	else{
		temp[x]+=sum;
		sum=temp[x];
		f(tree[x]);
	}
}
int main(){
	int n,i;
	
	while(scanf("%d",&n)!=EOF){
	summain=0;
		memset(tree,0,sizeof(tree));
		memset(temp,0,sizeof(temp));
		memset(vs,0,sizeof(vs));
		for(i=1;i<=n;i++){
			scanf("%d",&tree[i]);
			scanf("%d",&temp[i]);
			summain+=temp[i];
			if(temp[i]==0) vs[i]=1;
		}
		if(summain%3){
			cout<<-1<<endl;
			return 0;
		}
		memset(vis,0,sizeof(vis));
	    int s=0;
		for(i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==tree[j]) vis[i]=1;
			}
			if(temp[i]>1.0*summain/3) s=1;
		}	
		for(i=1;i<=n;i++){
			if(vis[i]==0){
				flag=0;
				sum=temp[i];
				f(tree[i]);
			}
		}
		int vi=0,z[5],u=0;
			memset(z,0,sizeof(z));
		
		for(i=1;i<=n;i++){
			if(temp[i]==1.0*summain/3&&vs[i]==0) {
				vi++;
				z[u++]=i;
			}
		
		}
		if(vi==2&&tree[z[0]]!=z[1]&&tree[z[1]]!=z[0]&&s==0) cout<<z[0]<<" "<<z[1]<<endl;
		else{
			cout<<-1<<endl;
		}
	}
}
