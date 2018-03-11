#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n;
	while(cin>>n){
		unsigned long long s=((n*(n+1)/2%10000)*(n*(n+1)/2%10000))%10000;
		if(s%10==s) {cout<<0<<0<<0<<s<<endl;
    		 }
    		 else if(s%100==s) {cout<<0<<0<<s<<endl;
    		 }
    		 else if(s%1000==s)cout<<0<<s<<endl;
    		 else cout<<s<<endl;
	}
}
