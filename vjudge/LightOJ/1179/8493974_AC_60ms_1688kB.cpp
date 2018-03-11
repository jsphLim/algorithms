#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath> 
using namespace std;
int main(){
      int n,m;
      int t,k=1;
      cin>>t;
	  while(t--){
	  	cin>>n>>m;
	  	int res=0;
	  	for(int i=2;i<=n;i++){
	  		res=(res+m)%i;
		  }
		  printf("Case %d: %d\n",k++,res+1);
	  }	
}