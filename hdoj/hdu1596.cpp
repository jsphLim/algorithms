#include<iostream>
using namespace std;
#define M 10000000
using namespace std;
double x,map[1050][1050],dis[1050];
int vis[1050],i,j,k,t;
int main()
{
    int n,m,st,en;
    while(scanf("%d",&n)!=EOF)
    {
        
        for(i=1;i<=n;i++)
        {for(j=1;j<=n;++j)
            {scanf("%lf",&x);map[i][j]=1-x;}}
        
        scanf("%d",&t);
        while(t--)
        {
           for(i=1;i<=n;i++)
             {dis[i]=1.0;vis[i]=0;}
               scanf("%d%d",&st,&en);
               if(st==en)
               {printf("1.000\n");continue;}
           dis[st]=0.0;
           for(i=1;i<=n;i++)
          {
            double mi=1.0;
            int k=-1;
            for(j=1;j<=n;j++)
            {
              if(!vis[j]&&dis[j]<mi)
              {mi=dis[j];k=j;}
            }
            if(mi==1){break;}
            vis[k]=1;
            for(j=1;j<=n;++j)
              {if(!vis[j]&&dis[j]>dis[k]+(1-dis[k])*map[k][j])
                {dis[j]=dis[k]+(1-dis[k])*map[k][j];}
              }
            }
            if((1-dis[en])==0)
            printf("What a pity!\n");
            else
               printf("%.3lf\n",1-dis[en]);
        }
    }
    return 0;
}
