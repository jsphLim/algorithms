#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define MAXN 1010
#define MAXM 20010
const int INF = (1<<24);
struct node{
    int u, v, w;
}edge[MAXM];
int n, m, top, d[MAXN];
void Init(){
    top = 0;
}
void add(int u, int v, int w){
    edge[top].u = u;
    edge[top].v = v;
    edge[top++].w = w;
}

int bellman_ford(){
    int i, j, u, v, w;
    for(i=1; i<=n; i++) d[i] = INF;
    d[1] = 0;
    for(i=1; i<n; i++){
        for(j=0; j<m; j++){
            u = edge[j].u;
            v = edge[j].v;
            w = edge[j].w;
            if(d[u] < INF && d[u]+w<d[v]){
                d[v] = d[u]+w;
            }
        }
    }

    for(j=0; j<m; j++){ //¼ì²â¸º»·
        u = edge[j].u;
        v = edge[j].v;
        w = edge[j].w;
        if(d[u] < INF && d[u]+w<d[v]){
            return 0;
        }
    }

    return 1;
}

int main(){
    int ml, md, i, u, v, w;
    scanf("%d %d %d", &n, &ml, &md);
    Init();
    m = ml+md;
    for(i=0; i<ml; i++){
        scanf("%d %d %d", &u, &v, &w);
        if(u>v) swap(u,v);
        add(u, v, w);
    }
    for(i=0; i<md; i++){
        scanf("%d %d %d", &u, &v, &w);
        if(u>v) swap(u,v);
        add(v, u, -w);
    }

    if(bellman_ford() == 0){
        printf("-1\n");
    }
    else if(d[n] == INF){
        printf("-2\n");
    }
    else printf("%d\n", d[n]);

    return 0;
}
