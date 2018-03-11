#include<iostream>
using namespace std;
int main(){
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		int flag=1;
		for(int i=2;i*i<=n;i++){
			if(n%i==0)
			{
				flag=0;break;
			}
		} 
		if(!flag&&n!=4) cout<<0<<endl;
		else if(n==4) cout<<2<<endl;
		else{
			cout<<n-1<<endl;
		}
	}
} 
