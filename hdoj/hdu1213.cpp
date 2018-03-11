#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXN 1005
using namespace std;
int fa[MAXN];
int sum;
void init(int x){
	for(int i=1;i<=x;i++)
	  fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]); 
}

void connect(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		sum++;fa[x]=y;
	}
	  
} 
int main() {  
    int t,m,a,b,n;  
  scanf("%d",&t);
  while(t--){ 
    sum=0;
  	scanf("%d%d",&n,&m);
  	init(n);
  	for(int i=0;i<m;i++){
  		scanf("%d%d",&a,&b);
  		connect(a,b);
	  }
	  printf("%d\n",n-sum);
  }
      
}  

