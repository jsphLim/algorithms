#include<bits/stdc++.h>
using namespace std;
#define inf 100000
#define Max 151
int dis[Max];
int vis[Max];
int mat[Max][Max];
map<string,int>m;
void dijk()
{
    int i,j,k,mindis;
    for(i=1; i<Max; i++)
        dis[i]=inf;
    vis[1]=1;
    dis[1]=0;
    for(i=1; i<Max; i++)
    {
        mindis=inf;
        k=1;
        for(j=1; j<Max; j++)
        {
            if(!vis[j]&&dis[j]<mindis)
            {
                mindis=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        for(j=1; j<Max; j++)
        {
            if(!vis[j]&&dis[j]>mat[k][j]+dis[k])
                dis[j]=mat[k][j]+dis[k];
        }
    }
}
int main()
{
    int t,i,j,l,n;
    char s[35],e[35],e1[35];
    while(cin>>t)
    {
        if(t==-1)
            break;
        for(i=1; i<Max; i++)
            for(j=1; j<Max; j++)
            {
                
                    mat[i][j]=inf;
            }
        m.clear();
        cin>>s>>e1;
        m[s]=1;
        n=2;
        if(!m[e1])
            m[e1]=n++;
        for(i=1; i<=t; i++)
        {
            cin>>s>>e>>l;
            if(!m[s])
                m[s]=n++;
            if(!m[e])
                m[e]=n++;
            if(mat[m[s]][m[e]]>l)
                mat[m[s]][m[e]]=mat[m[e]][m[s]]=l;
        }
        memset(vis,0,sizeof(vis));
        dijk();
        if(dis[m[e1]]==inf)
            cout<<-1<<endl;
        else
            cout<<dis[m[e1]]<<endl;
    }
    return 0;
}
