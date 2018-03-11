#include<bits/stdc++.h>
using namespace std;
#define INF 9999999
using namespace std;
int v[5][5]={{0,-3,-4,-2,-1},
			 {-3,5,-1,-2,-1},
			 {-4,-1,5,-3,-2},
			 {-2,-2,-3,5,-2},
			 {-1,-1,-2,-2,5}};
int dp[105][105];
int s1[105],s2[105];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int q=1;q<=n;q++){
            memset(s1,0,sizeof(s1));
            memset(s2,0,sizeof(s2));
            int l1,l2;
            scanf("%d ",&l1);
            int i,j;
            char a;
            dp[0][0]=0;
            for(i=1;i<=l1;i++){
                a=getchar();
                if(a=='A') s1[i]=1;
                else if(a=='C') s1[i]=2;
                else if(a=='G') s1[i]=3;
                else if(a=='T') s1[i]=4;
                dp[i][0]=dp[i-1][0]+v[s1[i]][0];
            }
            scanf("%d ",&l2);
            for(i=1;i<=l2;i++){
                a=getchar();
                if(a=='A') s2[i]=1;
                else if(a=='C') s2[i]=2;
                else if(a=='G') s2[i]=3;
                else if(a=='T') s2[i]=4;
                dp[0][i]=dp[0][i-1]+v[0][s2[i]];
            }
            
            for(i=1;i<=l1;i++){
                for(j=1;j<=l2;j++){
                	dp[i][j]=-INF;
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+v[s1[i]][0]);
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+v[0][s2[j]]);
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+v[s1[i]][s2[j]]);
                }
            }
            cout<<dp[l1][l2]<<endl;
        }
    }
    return 0;
}
