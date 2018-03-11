#include<bits/stdc++.h>
using namespace std;
int f(int x){
	return x==1?1:f(x/2)+1;
}
int main(){
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
	}
}
