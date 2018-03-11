#include<iostream>
#include<cstdio>
using namespace std;  
#define inf 0x3f3f3f3f
int ans;
int dfs(int l,int r)
{
    if(l<0) return ans;
    if(!l){
        ans=min(ans,r);
        return ans;
    }
    if(2*l<r+1) return ans;
    if(l==r) {
        return r;
    }
    dfs(l,2*r-l+1);
    dfs(l,2*r-l);
    dfs(2*l-r-1,r);
    dfs(2*l-r-2,r);
}
int main()
{
    int l,r;
    while(~scanf("%d%d",&l,&r)){
        ans=inf;
        ans=dfs(l,r);
        if(ans==inf)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}