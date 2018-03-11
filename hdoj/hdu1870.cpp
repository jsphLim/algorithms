#include<bits/stdc++.h>
using namespace std;
int main(){
	char ss[1000];
	stack<int> l;
	while(scanf("%s",ss)!=EOF){
		int len=strlen(ss);
		int sum=0;
		for(int i=0;i<len;i++){
			if(ss[i]=='(') {
				l.push(1);
		}
		else if(ss[i]==')'){
			l.pop();
		}
		else break;
		}
	   while(!l.empty()){
	   	sum+=l.top();
	   	l.pop();
	   }
	   cout<<sum<<endl;
	}
} 
