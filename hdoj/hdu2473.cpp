#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
using namespace std;
int par[100005];
int vis[100005];//¼ÇÂ¼½Úµã 
int flag;
set<int> S;
void init(int x) {
	for (int i = 0; i<x; i++) {
		vis[i] = i;
	}
}
int find(int x) {
	if (par[x] == x) return x;
	else 
		return par[x]=find(par[x]);
}
void unite(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b){
			return ;
		}
	else {
		par[a] = b;
	}
	return ;
}
int main(){  
    int n,m;  
    int sase = 0;  
    while(scanf("%d%d",&n,&m)){  
        if(n == 0 && m == 0) break;  
        sase++;  
        int cnt = n;  
        for(int i = 0;i < 100005;i++) par[i] = i;  
        for(int i = 0;i < n;i++) vis[i] = i;  
        while(m--){  
            char s[3];  
            int a,b;  
            scanf("%s",s);  
            if(s[0] == 'M'){  
                scanf("%d%d",&a,&b);  
                unite(vis[a],vis[b]);
            }  
            else{  
                scanf("%d",&a);  
                vis[a] = cnt++;  
            }  
        }  
        S.clear();  
        for(int i = 0;i < n;i++){  
            S.insert(find(vis[i]));  
        }  
        printf("Case #%d: %d\n",sase,S.size());  
    }  
    return 0;  
}  
