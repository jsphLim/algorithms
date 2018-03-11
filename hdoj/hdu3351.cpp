#include<bits/stdc++.h>
using namespace std;
char s[100005];
stack<char> ss;
void ismatch(char *s){
	ss.push(s[0]);
	for(int i=1;i<strlen(s);i++){
		if(!ss.empty()){
		   if(s[i]=='}') ss.pop();
		   else ss.push(s[i]);
	}
	else{
		 ss.push(s[i]);
	}
	} 
}
int main(){
	int cass=1;
	while(cin>>s){
		if(s[0] == '-') break;
		ismatch(s);
		int sum1=0;
		int sum2=0;
		while(!ss.empty()){
			char y = ss.top();
			if(y=='}') sum1++;
			else sum2++;
			ss.pop();
		}
		cout<<cass++<<". "<<(sum1+1)/2+(sum2+1)/2<<endl; 
		memset(s,0,sizeof(s));
	}
}
	
