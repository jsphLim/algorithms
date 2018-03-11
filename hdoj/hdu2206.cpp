#include<bits/stdc++.h>
using namespace std;
char s[20];
int main(){
	while(cin>>s){
	int ans[4],k=0;
	int bg=0,ed;
	memset(ans,0,sizeof(ans));
	for(int i=0;i<strlen(s);i++){
	    if(s[i]=='.'){
	    	ed=i;
			int p=1;
	    for(int j=ed-1;j>=bg;j--){	
	    	ans[k]+=(s[j]-'0')*p;
	    	p*=10;
	    }
	    k++;
	    bg=i+1;
	}
	}
	int u=strlen(s);
	int q=1;
	ans[3]=0;
	while(s[--u]!='.'){
		ans[3]+=(s[u]-'0')*q;
		q*=10;
	//	u--;
	}
	int flag=0;
	for(int i=0;i<4;i++)
	{
		if(ans[i]>255){
			flag=1;break;
		}
	}
	
	if(flag) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
}
	    
