#include<bits/stdc++.h>
using namespace std;
int father[105],n,m;
void init(int n){
	for(int i = 1; i <= n; i++)  
    {  
        father[i] = i;  
    }  
}
int find(int x)
{
	if(x != father[x])
		return father[x] = find(father[x]);
	return x;
}
int Union(int x, int y)
{
	int a = find(x), b = find(y);

	if(a != b)
	{
		father[a] = b;
		return 1;
	}
	return 0;
}
bool same(int x,int y){
	return find(x)==find(y);
} 
struct edge{
	int u,v,cost;
};
bool cmp(const edge&e1,const edge&e2){
	return e1.cost<e2.cost;
}
edge es[6000];
int kruskal(){
	sort(es,es+m,cmp);
	init(n);
	int res=0;
	for(int i=0;i<m;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			Union(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}
int main()
{
	while(scanf("%d", &n), n)
	{
		int i;
		m=n*(n-1)/2;
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
		}

		int res = kruskal();

		printf("%d\n", res);
	}

	return 0;
}

