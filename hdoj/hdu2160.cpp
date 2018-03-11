#include<bits/stdc++.h>
using namespace std;
struct node
{
 int w;
 int sp;
 int id;
}a[1010];
int cmp(node x,node y)
{
 if(x.w==y.w) return x.sp>y.sp;
 return x.w<y.w;
}
int dp[1010];
int vis[1010];
int rev[1010];
int main()
{
 int cnt=1,i,j,maxx=0,end;
      while(scanf("%d %d",&a[cnt].w,&a[cnt].sp)!=EOF)
   {
    a[cnt].id=++cnt;
   }
   memset(vis,0,sizeof(vis));
   sort(a+1,a+cnt+1,cmp);
   for(i=1;i<cnt;i++) dp[i]=1;
      for(i=1;i<cnt;i++)
   {
    for(j=1;j<i;j++)
    {
         if(a[i].w>a[j].w&&a[i].sp<a[j].sp&&dp[i]<dp[j]+1)
      {
       dp[i]=dp[j]+1;
       vis[i]=j;
      }
    }
   }
   end=1;
   maxx=dp[1];
   for(i=2;i<cnt;i++) if(maxx<dp[i]) {maxx=dp[i];end=i;}
   cout<<maxx<<endl;
   for(i=1;i<cnt;i++)
   {
   rev[i]=end;    
   	end=vis[end];
   }
   for(i=maxx;i>=1;i--)
   {
    cout<<a[rev[i]].id<<endl;
   }
     return 0;
   
}
