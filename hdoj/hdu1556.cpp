#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,n;
	
}a[1000500];
int ans[1000050];

void BuildTree(int l,int r,int i){
	a[i].l=l;
	a[i].r=r;
	a[i].n=0;
	if(l!=r){
		int mid=(l+r)/2;
		BuildTree(l,mid,2*i);  
        BuildTree(mid+1,r,2*i+1);
	}
}
void Update(int i,int x,int y){
	if(a[i].l==x&&a[i].r==y) a[i].n++;
	else{
		int mid=(a[i].l+a[i].r)/2;
		if(y<=mid){
			Update(2*i,x,y);
		}
		else if(x>mid) Update(2*i+1,x,y);
		else{
			Update(2*i,x,mid);
			Update(2*i+1,mid+1,y);
		}
	}
}
void Add(int x){
	int i;
	for(i=a[x].l;i<=a[x].r;i++){
		ans[i]+=a[x].n;
	}
	if(a[x].l==a[x].r) return ;
	Add(2*x);
	Add(2*x+1);
}

int main(){
	int n,a,b;
	while(scanf("%d",&n),n){
		BuildTree(1,n,1);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&b);
			Update(1,a,b);
		}
		memset(ans,0,sizeof(ans));
		Add(1);
		for(int i=1;i<n;i++) cout<<ans[i]<<" ";
		cout<<ans[n]<<endl; 
	}
}
