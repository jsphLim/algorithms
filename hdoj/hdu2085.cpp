#include<iostream>
using namespace std;
int main(){
	int t,m,n;
	while(cin>>t&&t!=-1){
		long long a=3,b=1,k,o;
		if(t==0) cout<<1<<", "<<0<<endl;
		else{
				 for(int i=1;i<t;i++){
		 	k=a*3+2*b;
		 	o=a+b;
		 	a=k;
		 	b=o;
		 }
		 cout<<a<<", "<<b<<endl;	
			
		}
	
	}
}
