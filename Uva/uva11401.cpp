#include<bits/stdc++.h>
using namespace std;
const int Mod = 1000007;
const int maxn = 500;
int C[maxn+5][maxn+5];
int main(){
	memset(C,0,sizeof(C));
	C[0][0]=1;
	for(int i=0;i<=maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	
	int t,kase=1;
	cin>>t;
	while(t--){
		int n,m,k,sum=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int s=0;s<16;s++){
			int b=0,r=n,c=m;
			if(s&1) { r--; b++;}
			if(s&2) { r--; b++;}
			if(s&4) { c--; b++;}
			if(s&8) { c--; b++;}
			if(b&1) sum=(sum+Mod-C[r*c][k])%Mod;
			else sum = (sum+C[r*c][k])%Mod;
		}
		printf("Case %d: %d\n",kase++,sum);
	}
	return 0;
}
