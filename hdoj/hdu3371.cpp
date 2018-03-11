#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int L=25005;  
struct edge{int u,v,cost;}es[L];  
int Fa[L],n,m,k;  //定点数和边数 
void init()//初始化并查集  
{  
    for(int i=0;i<=n;i++) Fa[i]=i;  
}  
int Find(int x)//查询属于哪个集合  
{  
    if(Fa[x]==x) return x;  
    else return Fa[x]=Find(Fa[x]);  
}  
void unite(int x,int y)//合并x,y两个元素  
{  
    x=Find(x);y=Find(y);  
    if(x==y) return ;  
    else {
    	Fa[y]=x; 
	} 
}  
bool same(int x,int y)//【判断是否属于同个集合  
{  
    return Find(x)==Find(y);  
}  
bool cmp(edge a,edge b)  
{  
    return a.cost<b.cost;  
}  
int kruskal(){
	int cnt=0;
	for(int i=1;i<=n;i++) if(Fa[i]==i) cnt++;
	sort(es,es+m,cmp);
	
	int res=0;
	for(int i=0;i<m;i++){
		if(cnt==1) break;
		if(!same(es[i].u,es[i].v)){
			unite(es[i].u,es[i].v);
			res+=es[i].cost;
			cnt--;
		}
	}
	if(cnt>1) return -1;
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++) scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
	int s,a[1005],b;
	init();
	for(int i=1;i<=k;i++){
		scanf("%d",&s);
		for(int j=0;j<s;j++) {
			scanf("%d",&a[j]);
			if(j>0)
			unite(a[j],a[j-1]);
		}
	    
	}
	cout<<kruskal()<<endl;
	
	}
}
