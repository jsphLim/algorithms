#include<iostream>  
#include<string.h>  
#include<stdlib.h>  
using namespace std; //并查集模板 日后使用 
int par[10005];  
int ranks[10005];  
int sum;  
void init(int n) {  
    for (int i = 0; i < n; i++) {  
        par[i] = i;  
        ranks[i] = 0;  
    }  
}  
int find(int x) {  
    if (par[x] == x) return x;  
    else return par[x] = find(par[x]);  
}  
void unite(int x, int y) {  
    x = find(x);  
    y = find(y);  
    if (x == y) return;  
    else {  
        par[x] = y;  
        sum--;  
    }  
}  
bool same(int x, int y) {  
    return find(x) == find(y);  
}  
int main() {  
    int t,m,n;  
  
        while(cin >> m ,m){  
            memset(par, 0, sizeof(par));  
            memset(ranks, 0, sizeof(ranks));  
        init(m);  
        sum = m - 1;  
        cin >> n;  
        int a, b;  
        for (int i = 0; i < n; i++) {  
            scanf("%d%d", &a,&b);  
            unite(a, b);  
        }  
        cout << sum << endl;  
    }  
      
}  
