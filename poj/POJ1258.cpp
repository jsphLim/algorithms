#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int map[1000][1000];
int dis[1000],n;
int vis[1000];
const int inf = 99999999 ;
int Prim(){  
    int i,j,k,tmp,ans;  
    for(i=1;i<=n;i++)  
    dis[i]=map[1][i];
    dis[1]=0;  
    for(i=1;i<=n;i++){  
        tmp=inf;  
        for(j=1;j<=n;j++){  
            if(!vis[j]&&tmp>dis[j]){  
                tmp=dis[j];  
                k=j;  
            }  
        }  
        ans+=dis[k];
        vis[k]=1;
        for(j=1;j<=n;j++){  
            if(!vis[j]&&dis[j]>map[k][j])  
            dis[j]=map[k][j];  
        }  
    }  
    return ans;
}  
int main()
{
    while (cin >> n)
    {
        for(int i=1;i<=n;i++)
           for(int j=1;j<=n;j++){
           	scanf("%d",&map[i][j]);
		   } 
		for(int i=1;i<=n;i++) dis[i]=inf;
		memset(vis,0,sizeof(vis));
        cout<<Prim()<<endl;  
   }
    return 0;
}
