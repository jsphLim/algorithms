#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	   int i=2;
	   while(n!=1){
	   	while(n%i==0){
	   		n=n/i;
	   		if(n!=1)
	   		cout<<i<<"*";
	   		else cout<<i<<endl;
		   }
		   i++;
	   }
	}
}
