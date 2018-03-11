#include<bits/stdc++.h>
using namespace std;
int main ( ) {  
    int t, give,cost, dp[300000],sum;  
    while(~scanf("%d",&t)) {  
        for(int i=1;i<=t;i++){  
            scanf("%d%d",&give,&cost);  
            dp[i]=give-cost; 
			dp[i + t]=give-cost;  
        }  
        int u=0,ans=0;sum=0;
		int i;  
        for (i = 1;i<=2*t;i++){
		    if(u>=t) break;  
            sum+=dp[i];  
            u++;  
            if (sum<0)
                sum=u=0;    
            if (u>ans) ans=u;    
        }  
        if (ans>t) ans=t;  
        printf ("%d\n",ans);  
    }  
}  
