#include<bits/stdc++.h>

using namespace std;

int n,dp[105][255];    
int money[5]={1,5,10,25,50};
int sum=0;
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<5;i++)
            for(int j=1;j<=100;j++)
                for(int k=n;k>=money[i];k--)  
                    dp[j][k]+=dp[j-1][k-money[i]];
                    sum=0;
        for(int i=0;i<=100;i++) 
            sum+=dp[i][n];
        cout<<sum<<endl;
    }
    return 0;
}
