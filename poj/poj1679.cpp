#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include<functional>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int N=11000;
const int M=15005;
int n,m,cnt;
int parent[N];
bool flag;
struct man {
    int u,v,w;
    int eq,used,del;
} edg[N];
bool cmp(man g,man h) {
return g.w<h.w;
}
void init() {
    for(int i=0; i<=10005; i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}//查找并返回节点x所属集合的根节点
void Union(int x,int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    parent[y] = x;
}//将两个不同集合的元素进行合并
int Kruskal() {
    init();
   int sum=0;
   int num=0;
   for(int i=0;i<m;i++){
    if(edg[i].del==1)continue;
    int u=edg[i].u;int v=edg[i].v;int w=edg[i].w;

    if(Find(u)!=Find(v)){
        sum+=w;
        if(!flag)edg[i].used=1;
        num++;
        Union(u,v);
    }
    if(num>=n-1)break;
   }
   return sum;
}
int main() {
    int t,d;
    cin>>t;
    while(t--) {
        cnt=0;
        cin>>n>>m;
        for(int i=0; i<m; i++) {
            cin>>edg[i].u>>edg[i].v>>edg[i].w;
            edg[i].del=0;
            edg[i].used=0;
            edg[i].eq=0;//一开始这个地方eq没有初始化，WA了好几发，操
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)continue;
                if(edg[i].w==edg[j].w)edg[i].eq=1;
            }
        }
        sort(edg,edg+m,cmp);
        flag=false;
        cnt=Kruskal();
        flag=true;
        bool gg=false;
        for(int i=0;i<m;i++){
            if(edg[i].used==1&&edg[i].eq==1){
                edg[i].del=1;
                int s=Kruskal();//printf("%d %d\n",i,s);
                if(s==cnt){
                    gg=true;
                    printf("Not Unique!\n");
                    break;
                }
                edg[i].del=0;
            }
        }
        if(!gg)cout<<cnt<<endl;
    }
    return 0;
}
