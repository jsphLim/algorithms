#include<bits/stdc++.h>
using namespace std;
int main(){
	long long arr[105],i,j,n;
	while(cin>>n,n){
		for(i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		cout<<arr[n-1]*(2009-n+1)+accumulate(arr,arr+n-1,0)<<endl;
		}
}
