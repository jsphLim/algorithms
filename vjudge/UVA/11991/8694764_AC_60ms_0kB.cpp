#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int d[10005];
int main(int argc, char *argv[]) 
{
	map<int,vector<int> > a;
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		a.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(!a.count(x)) a[x]=vector<int>();
			a[x].push_back(i+1);
		}
		while(m--){
			scanf("%d%d",&x,&y);
			if(!a.count(y)||a[y].size()<x) printf("0\n");
			else printf("%d\n",a[y][x-1]);
		}
	}
	
	return 0;
}
