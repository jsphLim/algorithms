#include<iostream>
using namespace std;
int num[1000005];
int main(){
	int n,i,j;
	while(cin>>n,n){
		for(i=0;i<n;i++) scanf("%d",&num[i]);
		int vis=0;
		for(i=0;i<n;i++){
			vis^=num[i];
		}
		cout<<vis<<endl;
	}
}
