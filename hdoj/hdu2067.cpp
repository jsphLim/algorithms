#include<bits/stdc++.h>
using namespace std;
long long qi[40][40];
int main(){
	
	int i,j;
	int n;	
	n=36;
	memset(qi,0,sizeof(qi));
	for(i=0;i<n;i++)
	for(j=0;j<i;j++) qi[i][j]=0;

	 for(i=0;i<n;i++) qi[0][i]=1;
	 for(i=1;i<n;i++)
	 for(j=i-1;j<n;j++){

	 	qi[i][j]=qi[i-1][j]+qi[i][j-1];
	 }
	 int k=1;
	while(cin>>n&&n!=-1){
		if(n==1) printf("%d %d %d\n",k++,n,2);
		else printf("%d %d %lld\n",k++,n,qi[n-1][n-1]*2);
	}

	 
}
