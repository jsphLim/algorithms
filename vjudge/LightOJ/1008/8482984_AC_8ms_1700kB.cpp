#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
struct node{
	int x;
	int y;
}s[100];
int main(){
      long long n,x,t,y,s;
      cin>>t;
      int kcase=1;
      while(t--){
      	cin>>s;
      	n=ceil((double)sqrt(s));
      	if(n*n-s<n)x=n,y=n*n-s+1;
       else x=-n*n+2*n+s-1,y=n;
        if(n%2!=0)swap(x,y);
        printf("Case %d: %lld %lld\n",kcase++,x,y);
	  }
} 