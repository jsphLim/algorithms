#include<cstdio>  
#include<ctime>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
typedef long long LL;  
const int maxn = 100005;  
int T, n, m, ans, x[maxn], y[maxn];  
  
bool check(int a, int b, int c)  
{  
    LL x1 = x[a] - x[b], x2 = x[a] - x[c];  
    LL y1 = y[a] - y[b], y2 = y[a] - y[c];  
    return x1*y2 == x2*y1;  
}  
  
int main()  
{  
    while (scanf("%d%d", &n, &m) != EOF)  
    {  
        ans = n * m;  
        for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);  
        srand(time(0));  
        bool flag = false;  
        if (n <= 2) flag = true; else   
        for (int i = 1; i <= 1000; i++)  
        {  
            int u = rand() % n, v, cnt = 2;  
            for (v = rand() % n; v == u; v = rand() % n);  
            for (int j = 0; j < n; j++)  
                if (j != v&&j != u&&check(u, v, j)) cnt++;  
            if (cnt * 100 >= ans) { flag = true; break; }  
        }  
        if (flag) printf("possible\n"); else printf("impossible\n");  
    }  
    return 0;  
}  