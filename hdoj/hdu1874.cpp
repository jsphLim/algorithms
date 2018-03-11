#include<bits/stdc++.h>
#define inf 1<<30
using namespace std;
int vis[1050];
int dij[1050];
int mp[1050][1050];
int sn=0,i,j,n;
void di(int st,int ed)  
{  
    int i,j,p,Min;  
    for(i=0;i<n;i++)  
    {  
        dij[i]=mp[st][i];  
    }  
    memset(vis,0,sizeof(vis));  
    vis[st]=1;  
    for(i=0;i<n;i++)  
    {  
        Min=inf;  
        for(j=0;j<n;j++)  
        if(!vis[j]&&dij[j]<Min)  
        {  
            p=j;  
            Min=dij[j];  
        }  
        vis[p]=1;  
        for(j=0;j<n;j++)  
        {  
            if(!vis[j]&&mp[p][j]<inf)  
            {  
                if(dij[j]>dij[p]+mp[p][j])  
                {  
                    dij[j]=dij[p]+mp[p][j];  
                }  
            
            }  
        }  
    }  
}  
int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b,d,p;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			mp[i][j]=inf;
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&d);
			if(mp[a][b]>d){
			mp[a][b]=mp[b][a]=d;

		}
		}
	    int st,en;
	    scanf("%d%d",&st,&en);
	    di(st,en);
	    if(st==en) cout<<0<<endl;
	    else if(dij[en]==inf) cout<<-1<<endl;
	    else
		cout<<dij[en]<<endl;

	}
}
