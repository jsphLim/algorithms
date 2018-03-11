#include<iostream>
#include<cstdio>
#include<string.h>
#define MAXN 10000005
using namespace std;
int fa[MAXN];
int maxx=1;
int visa[MAXN];
void init(int x){
	for(int i=1;i<=x;i++){
	  fa[i]=i;
	  visa[i]=1;
}
}
int find(int x){
	if(fa[x]==x)return x;//�Լ���ͷ
	return fa[x]=find(fa[x]); 
}

void connect(int x,int y){
	x=find(x);
	y=find(y);//�ҵ��������ͷ 
	if(x!=y){
	  fa[x]=y;//������һ�����ͷ������һ�����ͷ 
	  visa[y]+=visa[x];
	  if(visa[y]>maxx) maxx=visa[y]; 
}
}
int main(){
	int n,a,b;
	while(~scanf("%d",&n)){
		init(10000005);
		maxx=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&b);
			connect(a,b);
		}
		cout<<maxx<<endl;
} 
}

