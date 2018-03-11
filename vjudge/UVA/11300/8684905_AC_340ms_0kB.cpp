#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 1000000+5;
long long A[maxn],C[maxn];
int main(){
	int n;
	while(~scanf("%d",&n)){
		long long sum=0;
		for(int i=0;i<n;i++){
			scanf("%I64d",&A[i]);
			sum+=A[i];	
		} 
		long long as = sum/n;
		C[0]=0;
		for(int i=0;i<n;i++) C[i]=C[i-1]+A[i]-as;
		sort(C,C+n);
		long long ans = C[n/2],x=0;
		for(int i=0;i<n;i++) x+=abs(ans-C[i]);
		cout<<x<<endl;
	}
}