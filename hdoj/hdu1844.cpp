#include<bits/stdc++.h>
using namespace std;
int bao[100000];
int main(){
	int i,j,kcase=1;
	while(cin>>bao[0]>>bao[1]>>bao[2]>>bao[3]>>bao[4]>>bao[5]){
		if(bao[0]==0&&bao[1]==0&&bao[2]==0&&bao[3]==0&&bao[4]==0&&bao[5]==0) break;
		int dp[100000];
		int sum=0;
		for(i=0;i<6;i++) sum+=(i+1)*bao[i];
			if(sum%2) {
			printf("Collection #%d:\n",kcase++);
			printf("Can't be divided.\n");	
			}
			else{
				memset(dp,-1,sizeof(dp));
		    dp[0]=0;
		    for(i=0;i<6;i++){
			for(j=0;j<=sum/2;j++){
				if(dp[j]>=0){
					dp[j]=bao[i];
				}
				else if(j<(i+1)||dp[j-(i+1)]<=0){
					dp[j]=-1;
				}
				else{
					dp[j]=dp[j-(i+1)]-1;
				}
			}
		}
		if(dp[sum/2]>=0){
			printf("Collection #%d:\n",kcase++);
			printf("Can be divided.\n");	
		}	
		else{
			printf("Collection #%d:\n",kcase++);
			printf("Can't be divided.\n");	
		}	
			
			
		}
		cout<<endl;
		
		
		
		
	}
}
