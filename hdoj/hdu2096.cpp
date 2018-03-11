#include<iostream>
using namespace std;
int main(){
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		m%=100;
		n%=100;
		cout<<(m+n)%100<<endl;
	}
}
