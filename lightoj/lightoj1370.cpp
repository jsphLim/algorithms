#include<bits/stdc++.h>
using namespace std;
int phi(int x){
	int ans=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) {
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}
int main(){
	int t,n,sum=0,a;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		while(n--){
		 scanf("%d",&a);
		 sum+=phi(a);
		}
		cout<<sum<<endl;
		printf("%d\n",phi(9));
	}
}
