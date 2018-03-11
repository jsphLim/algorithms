#include<bits/stdc++.h>
using namespace std;
int dp1[200005];
int dp2[200005]; 
int main(){  
    int n,m,cost;  
    while(~scanf("%d%d",&n,&m)){  
        for(int i=2;i<=n+1;++i){  
            for(int j=2;j<=m+1;++j){  
                scanf("%d",&cost);  
                dp1[j]=max(dp1[j-1],dp1[j-2]+cost);
            }  
            dp2[i]=max(dp2[i-1],dp2[i-2]+dp1[m+1]);  
        }  
        printf("%d\n",dp2[n+1]); 
    }  
    return 0;  
}   
