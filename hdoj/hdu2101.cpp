#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(){
	int m,n;
	while(cin>>m>>n){
		if((m+n)%86==0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
} 
