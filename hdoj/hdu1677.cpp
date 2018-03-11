#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20010;
int a[MAXN];
struct node
{
    int w;
    int h;
}ans[MAXN];
int n;
bool cmp(node x,node y)
{
    if(x.w==y.w)
        return x.h<y.h;  ///从小到大
    else
        return x.w>y.w;  ///从大到小
}
int Binary_Search(int len,int num)
{
    int low,high,mid;
    low = 0;
    high = len;
    while(low<high)
    {
        mid = (low+high)/2;
        if(a[mid] <= num)
            low = mid+1;
        else
            high = mid;
    }
    return low;
}
int LIS(){
	int len = 0;
        memset(a,0,sizeof(a));
	for(int i = 0; i < n; i++)
        {
            int pos = Binary_Search(len,ans[i].h);
            a[pos] = ans[i].h;
            if(pos==len)
                len++;
        }
        return len;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d%d",&ans[i].w,&ans[i].h);
        sort(ans,ans+n,cmp);
        cout<<LIS()<<endl;
    }
    return 0;
}

