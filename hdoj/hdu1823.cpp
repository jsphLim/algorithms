#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cstdlib>
#include <sstream>
using namespace std;
typedef long long LL;
const int INF=0x5fffffff;
const double EXP=1e-6;
const int MS=1001;

struct active
{
      int l,r;
      double maxv;
      int mid()
      {
            return (l+r)>>1;
      }
};

struct node
{
      int l,r;
      active actives[4*MS];
      int mid()
      {
            return (l+r)>>1;
      }
}nodes[405];

void init()
{
      for(int i=0;i<405;i++)
            for(int j=0;j<4*MS;j++)
                  nodes[i].actives[j].maxv=-1;
}

void creat_a(int p,int root,int l,int r)
{
      nodes[p].actives[root].l=l;
      nodes[p].actives[root].r=r;
      if(nodes[p].actives[root].l==nodes[p].actives[root].r)
            return ;
      int mid=(l+r)/2;
      creat_a(p,root<<1,l,mid);
      creat_a(p,root<<1|1,mid+1,r);
}

void creat(int root,int l,int r)
{
      nodes[root].l=l;
      nodes[root].r=r;
      creat_a(root,1,0,MS);
      if(nodes[root].l==nodes[root].r)
            return ;
      int mid=(l+r)/2;
      creat(root<<1,l,mid);
      creat(root<<1|1,mid+1,r);
}

void insert_a(int p,int root,int pos,double value)
{
      if(nodes[p].actives[root].maxv<value)
            nodes[p].actives[root].maxv=value;
      if(nodes[p].actives[root].l==nodes[p].actives[root].r)
            return ;
      if(pos<=nodes[p].actives[root].mid())
            insert_a(p,root<<1,pos,value);
      else
            insert_a(p,root<<1|1,pos,value);
}

void insert(int root,int pos,int value,double s)
{
      insert_a(root,1,value,s);
      if(nodes[root].l==nodes[root].r)
            return ;
      if(pos<=nodes[root].mid())
            insert(root<<1,pos,value,s);
      else
            insert(root<<1|1,pos,value,s);
}

double query_a(int p,int root,int l,int r)
{
      double ans=-1;
      if(nodes[p].actives[root].l>=l&&nodes[p].actives[root].r<=r)
            return nodes[p].actives[root].maxv;
      if(l<=nodes[p].actives[root].mid())
            ans= max(ans,query_a(p,root<<1,l,r));
      if(r>nodes[p].actives[root].mid())
            ans=max(ans,query_a(p,root<<1|1,l,r));
      return ans;
}

double query(int root,int l1,int r1,int l2,int r2)
{
      double ans=-1;
      if(nodes[root].l>=l1&&nodes[root].r<=r1)
            return query_a(root,1,l2,r2);
     // 如果是叶子节点会在上一条语句中返回。
      if(l1<=nodes[root].mid())
            ans=max(ans,query(root<<1,l1,r1,l2,r2));
      if(r1>nodes[root].mid())
            ans=max(ans,query(root<<1|1,l1,r1,l2,r2));
      return ans;
}

int main()
{
      int n,h1,h2;
      double a1,a2,fate;
      creat(1,100,200);
      while(scanf("%d",&n)==1&&n)
      {
            init();
            char cmd[MS];
            while(n--)
            {
                  scanf("%s",cmd);
                  if(cmd[0]=='I')
                  {
                        scanf("%d %lf %lf",&h1,&a1,&fate);

                        insert(1,h1,(int)(a1*10+EXP),fate);
                  }
                  else
                  {
                        scanf("%d %d %lf %lf",&h1,&h2,&a1,&a2);
                        if(h1>h2)
                              swap(h1,h2);
                        if(a1>a2)
                              swap(a1,a2);
                        double ans=query(1,h1,h2,(int)(a1*10+EXP),(int)(a2*10+EXP));
                        if(ans>=0)
                              printf("%.1lf\n",ans);
                        else
                              printf("-1\n");
                  }
            }
      }
      return 0;
}

