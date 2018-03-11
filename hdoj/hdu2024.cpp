#include<bits/stdc++.h>
using namespace std;
char a[100];
int main(){
	int t;
	cin>>t;
	int i;
	getchar();
	while(t--){
		gets(a);
		int flag=0;
		int len=strlen(a);
		if(a[0]!='_'&&!isalpha(a[0])){
			cout<<"no"<<endl;
			continue;
		}
		for(i=1;i<len;i++){
			if(a[i]!='_'&&!isalnum(a[i])){
			flag=1;
			break;}
		}
		if(flag) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}
