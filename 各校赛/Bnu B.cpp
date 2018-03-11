#include<bits/stdc++.h>
using namespace std;
char s[100000];
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='0') cout<<0;
			else if(s[i]=='6') cout<<6;
			else if(s[i]=='2') cout<<2;
			else if(s[i]=='4') cout<<4;
			else if(s[i]=='9') cout<<9;
			else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o') {cout<<2;}
			else if(s[i]=='z'&&s[i+1]=='e'&&s[i+2]=='r'&&s[i+3]=='o') {cout<<0;}
			else if(s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='u'&&s[i+3]=='r') {cout<<4;}
			else if(s[i]=='s'&&s[i+1]=='i'&&s[i+2]=='x') {cout<<6;}
			else if(s[i]=='n'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='e') {cout<<9;}
		}
		cout<<endl;
		memset(s,0,sizeof(s));                         
	}
}                                                                           
