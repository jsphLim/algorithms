#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	while(cin>>k,k){
		int res=0;
		for(int j=k;j<=2k;j++)
		for(int i=2;i<=2*k;i++) res=(res+j)%i;
		
		
		cout<<res+1<<endl;
	}
	
}
