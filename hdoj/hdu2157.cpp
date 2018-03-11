#include <bits/stdc++.h>
using namespace std;  
int mp[1005][1005]; 
int dp[1005][1005];  
int main()  
{  
    int m,n,a,b;
	while(scanf("%d%d",&n,&m)&&(m+n)){
		
		memset(mp,0,sizeof(mp));
        for(int i=1;i<=m;i++){
		   		scanf("%d%d",&a,&b);
		   		mp[a][b]=1;
		   	}	
			
		   	int u,st,ed,k;
		   	scanf("%d",&u);
		   	while(u--){
		   		scanf("%d%d%d",&st,&ed,&k);
				   memset(dp,0,sizeof(dp));
		   		dp[0][st]=1;
			for(int i=1;i<=k;i++) 
				for(int r=0;r<n;r++)
					for(int j=0;j<n;j++)
						if( mp[r][j] ){
							dp[i][j]+=dp[i-1][r];
							dp[i][j]%=1000;
						}
		   		 cout<<dp[k][ed]<<endl;
			   }
	   	      
	} 
}  
