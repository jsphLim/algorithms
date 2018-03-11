#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
	char s[100];
	int n;
	int t,kase=1;
	cin>>t;
	while(t--){
		scanf("%d %s",&n,s);
		int f=0;
		if(s[0]=='B') f=1;
		if(f==0){
			if(n%3==1) printf("Case %d: Bob\n",kase++);
			else printf("Case %d: Alice\n",kase++);
			
		}
		else{
			if(n%3==0) printf("Case %d: Alice\n",kase++);
			else printf("Case %d: Bob\n",kase++);
		}
	}
}