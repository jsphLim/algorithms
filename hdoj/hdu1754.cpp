#include <bits/stdc++.h>
using namespace std;
int sum,n;
struct node
{
    int l,r,n;
} a[30000000];
void init()//新建一个线段树
{
    int i,k;
    for(k = 1; k<n; k<<=1);
    for(i = k; i<2*k; i++)
    {
        a[i].l = a[i].r = i-k+1;
        a[i].n = 0;
    }
    for(i = k-1; i>0; i--)
    {
        a[i].l = a[2*i].l;
        a[i].r = a[2*i+1].r;
        a[i].n = 0;
    }
}
void insert(int i,int x,int m)//线段树的插入
{
    if(x>=a[i].l && x<=a[i].r)
        a[i].n=m;
    if(a[i].l == a[i].r)
        return ;
    int mid = (a[i].l+a[i].r)/2;
    if(x>mid)
        insert(2*i+1,x,m);
    else
        insert(2*i,x,m);
}
int find(int x,int y,int i)//线段树的查询
{
    if(a[i].l == x && a[i].r == y)
    {
        return a[i].n;
    }

    int mid = (a[i].l+a[i].r)/2;
    if(x>mid)
       return find(x,y,2*i+1);
    else if(y<=mid)
       return find(x,y,2*i);
    else
    {
        return max(find(x,mid,2*i),find(mid+1,y,2*i+1));
    }
    
}

int main()
{
    int x,y,i,j,k,m;
    char c;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&k);
            insert(1,i,k);
        }
        while(m--)
        {
		    scanf(" %c",&c);
            scanf("%d%d",&x,&y);
            if(c=='U')
                insert(1,x,y);
            else if(c=='Q')
            {
                printf("%d\n",find(x,y,1));
            }
        }
    }

    return 0;
}
//上面的是自己写的超时线段树。。。也是服了 

/*#include <cstdio>  
#include <algorithm>  
using namespace std;  
  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int maxn = 200005;  
int MAX[maxn << 2];  
  
void PushUP(int rt)  
{  
    MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);  
}  
  
void build(int l,int r,int rt)  
{  
    if(l == r)  
    {  
        scanf("%d",&MAX[rt]);  
        return ;  
    }  
    int m = (l+r)>>1;  
    build(lson);  
    build(rson);  
    PushUP(rt);  
}  
  
void update(int p,int y,int l,int r,int rt) //  
{  
    if(l == r)  
    {  
        MAX[rt] = y;  
        return ;  
    }  
    int m = (l+r)>>1;  
    if(p<=m)  
        update(p,y,lson);  
    else  
        update(p,y,rson);  
    PushUP(rt);  
}  
  
int query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l && r<=R)  
        return MAX[rt];  
    int m = (l+r)>>1;  
    int ret = 0;  
    if(L<=m)  
        ret = max(ret,query(L,R,lson));  
    if(R>m)  
        ret = max(ret,query(L,R,rson));  
    return ret;  
}  
  
int main()  
{  
    int n,m;  
    while(~scanf("%d%d",&n,&m))  
    {  
        build(1,n,1);  
        char str[2];  
        int a,b;  
        while(m--)  
        {  
            scanf("%s%d%d",str,&a,&b);  
            if(str[0] == 'Q')  
                printf("%d\n",query(a,b,1,n,1));  
            else  
                update(a,b,1,n,1);  
        }  
    }  
  
    return 0;  
}  */
