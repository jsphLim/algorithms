#include<bits/stdc++.h>
using namespace std;
int ans[11];
long long test[10000];
long long n;
int main(){
	long long sum=0;
	while(cin>>n,n){
		int i,j,k,s=0,nod=0;
		memset(ans,0,sizeof(ans));
	for(int u=10;u<=n;u++){
	    int x=u; 
		nod=0;
		while(x){
			ans[nod++]=x%10;
			x/=10; 
		}
		for(i=0;i<nod;i++){
			sum=0;
			for(j=0;j<i;j++) sum+=pow(10,j)*ans[j];
			for(k=i+1;k<nod;k++) sum+=pow(10,k-1)*ans[k];
			sum+=u;
			if(sum==n) test[s++]=u;
		}
	}
	if(s==0) printf("No solution.\n");
	else{
		sort(test,test+s);
		for(i=0;i<s-1;i++) printf("%lld ",test[i]);
		printf("%lld\n",test[s-1]);
	}
	}
}
