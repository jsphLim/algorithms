#include<bits/stdc++.h>
#define inf 1<<30
using namespace std;
int vis[1000];
int dij[1000];
int mp[1000][1000];
int cost[1000][1000];
int v[1000];
int sn=0,i,j,n;
void di(int st,int ed)  
{  
    int i,j,p,Min;  
    for(i=1;i<=n;i++)  
    {  
        dij[i]=mp[st][i];  
        v[i]=cost[st][i];  
    }  
    memset(vis,0,sizeof(vis));  
    vis[st]=1;  
    for(i=1;i<n;i++)  
    {  
        Min=inf;  
        for(j=1;j<=n;j++)  
        if(!vis[j]&&dij[j]<Min)  
        {  
            p=j;  
            Min=dij[j];  
        }  
        vis[p]=1;  
        for(j=1;j<=n;j++)  
        {  
            if(!vis[j]&&mp[p][j]<inf)  
            {  
                if(dij[j]>dij[p]+mp[p][j])  
                {  
                    dij[j]=dij[p]+mp[p][j];  
                    v[j]=v[p]+cost[p][j];  
                }  
                else if(dij[j]==dij[p]+mp[p][j])  
                {  
                    if(v[j]>v[p]+cost[p][j])  
                    v[j]=v[p]+cost[p][j];  
                }  
            }  
        }  
    }  
}  
int main(){
	int m;
	while(scanf("%d%d",&n,&m)){
		if(m==0&&n==0) break;
		int a,b,d,p;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			mp[i][j]=inf;
			cost[i][j]=inf;
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(mp[a][b]>d){
			mp[a][b]=mp[b][a]=d;
			cost[a][b]=cost[b][a]=p;
		}
		}
	    int st,en;
	    scanf("%d%d",&st,&en);
	    di(st,en);
		cout<<dij[en]<<" "<<v[en]<<endl;

	}
}
