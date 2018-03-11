#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
char mp[100][100];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(mp,0,sizeof(mp));
		for(int i=1; i<=n; i++)
			scanf("%s",mp[i]+1);
		
		int m=strlen(mp[1]+1);
		int ans=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) {
				if(mp[i][j]=='R')
					if(!(mp[i-1][j-1]=='R'||mp[i-1][j-1]=='G')) ans++;

			}
			
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) {
				if(mp[i][j]=='B')
						if(!(mp[i-1][j+1]=='B'||mp[i-1][j+1]=='G')) ans++;

			}
			
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) {
				if(mp[i][j]=='G')
					if(!(mp[i-1][j-1]=='R'||mp[i-1][j-1]=='G')) ans++;

			}	
			
			for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) {
				if(mp[i][j]=='G')
						if(!(mp[i-1][j+1]=='B'||mp[i-1][j+1]=='G')) ans++;

			}	
			
			
			
			    
		cout<<ans<<endl;
	}
}
