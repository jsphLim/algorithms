#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>  
using namespace std;

//int main(){
//	int n;
//	while(cin>>n,n){
//		for(int i=0;i<n;i++) cin>>d[i];
//		dp[0]=d[0];
//		for(int i=1;i<n;i++){
//			if(dp[i-1]<0) dp[i]=d[i];
//			else dp[i]=dp[i-1]+d[i];
//		}
//		for(int i=0;i<n;i++) cout<<dp[i]<<" ";
//		cout<<endl;
//	}
//	
//	
//} 
long long dp[21];  
int n,k,i;  
int main()  
{  
    while(~scanf("%d%d",&n,&k))  
    {       
         dp[1]=k-1; dp[2]=(k-1)*k;  
         for (i=3;i<=n;i++)  
            dp[i]=(k-1)*(dp[i-1]+dp[i-2]);  
         printf("%lld\n",dp[n]);                           
    }  
    return 0;     
}  