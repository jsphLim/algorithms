#include<iostream>  
#include<cstdio>  
  
using namespace std;  
int pre[1005],in[1005],n,cnt;  
  
void ListTree(int l,int r)  
{  
    if(l>r)  
        return;  
    cnt++;  
    if(l==r)  
    {  
        printf("%d ",in[l]);  
        return;  
    }  
    int rt=cnt;  
    for(int i=l;i<=r;i++)  
        if(in[i]==pre[rt])  
        {  
            ListTree(l,i-1);  
            ListTree(i+1,r);  
            break;  
        }  
    printf("%d",pre[rt]);  
    if(rt>1)
        putchar(' ');  
}  
  
int main()  
{  
    while(~scanf("%d",&n))  
    {  
        for(int i=1;i<=n;i++)  
            scanf("%d",pre+i);  
        for(int i=1;i<=n;i++)  
            scanf("%d",in+i);  
        cnt=0;  
        ListTree(1,n);  
        putchar('\n');  
    }  
}  
