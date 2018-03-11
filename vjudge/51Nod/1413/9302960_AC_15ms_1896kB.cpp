#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
	char s[10];
bool serch(){
	for(int i=0;i<strlen(s);i++){
		if(s[i]!='0') return true;
	}
	return false;
}
int main(){
	int n;
	while(~scanf("%s",&s)){
		int ans=0;
	while(serch()){
		for(int i=0;i<strlen(s);i++){
			if(s[i]-'0'>0) s[i]=((s[i]-'0')-1)+'0';
		}
		ans++;
	}
	cout<<ans<<endl;
	memset(s,0,sizeof(s));
}
		
}