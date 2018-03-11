#include<bits/stdc++.h>
using namespace std;
int Powermod(int a,int b,int c){
	int ans=1;
	a%=c;
	while(b>0){
		if(b%2==1) ans=(ans*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}
int main(){
        int a,b;
	while(cin>>a>>b){
		if(a==0&&b==0) break;
		cout<<Powermod(a,b,1000)<<endl;
	}
}
