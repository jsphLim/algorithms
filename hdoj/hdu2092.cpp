#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,i,j,m;
	while(cin>>n>>m){
	if(n==0&&m==0) break;
	if(sqrt(n*n-4*m)==(int)sqrt(n*n-4*m)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
}
