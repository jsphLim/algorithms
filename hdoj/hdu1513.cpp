#include<bits/stdc++.h>
using namespace std;
int dp[2][5555];
char a[5555];
char b[5555];
int main(){
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s",a);
		for(int i=0;i<n;i++) b[i]=a[i];
		strrev(b);
		for(int i=0;i<n;i++)
		   for(int j=0;j<n;j++){
		   	int k=i%2;
		   	int r=1-k;
		   	if(a[i]==b[j])
		   	dp[k][j]=dp[r][j-1]+1;
		   	else dp[k][j]=max(dp[r][j],dp[k][j-1]);
		   }
		   printf("%d\n",n-dp[(n-1)%2][n-1]);
	}
}

