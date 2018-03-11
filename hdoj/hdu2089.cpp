#include <bits/stdc++.h>
using namespace std;
int vis[1000010];
main()
{
    char buf[100];
    int i,n,m;
    memset(vis,0,sizeof(vis));
    	for(i=4;i<=1000010;i++){
    		memset(buf,0,sizeof(buf));
    		sprintf(buf,"%d",i);
    		for(int j=0;j<strlen(buf);j++){
    			if(buf[j]=='4'||(buf[j]=='6'&&buf[j+1]=='2')){	
    				vis[i]=1;
    				break;
				}
			}
		}
    while (scanf("%d%d",&n,&m)){
    	if(m==0&&n==0) break;
    	int sum=0;
        for(i=n;i<=m;i++) {
        	if(vis[i]==1) sum++; 
		}
    	cout<<m-n-sum+1<<endl;
    	
    	
	}
}
