#include<iostream>
#include<math.h>
using namespace std;
bool su(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int m;
	while(cin>>m,m){
		int sum=0;
		for(int i=2;i<m/2;i++){
			if(su(i)&&su(m-i)) sum++;
		}
		cout<<sum<<endl;
	}
}
