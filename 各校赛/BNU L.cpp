#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int t;
	cin>>t;
	char s[10];
	int flag1,flag2;
	while(t--){
		int n;
		int one=1500,two=1500;
		flag1=flag2=0;
		scanf("%d",&n);
		while(n--){
			scanf("%s",s);
			if(s[0]=='g'){
				if(one>two) two+=100;
				else one+=100;
				if(one>3299) one=3299;
				if(two>3299) two=3299;
				if(one<0) one=0;
				if(two<0) two=0; 
			}
			else{
				if(one>two) two-=100;
				else one-=100;
				if(one>3299) one=3299;
				if(two>3299) two=3299;
				if(one<0) one=0;
				if(two<0) two=0;
			}
		}
		int maxx=max(one,two);
		if(maxx>3299) cout<<3299<<endl;
		else if(maxx<0) cout<<0<<endl;
		else cout<<maxx<<endl;
	}
}
