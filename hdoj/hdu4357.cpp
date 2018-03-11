#include<bits/stdc++.h>
using namespace std;
char a[1000];
char b[1000];
int main(){
	int t;
	cin>>t;
	int kcase=1;
	while(t--){
		cin>>a>>b;
		int len=strlen(a);
		if(len>2){
		int s=0,s1=0;
		for(int i=0;i<len;i++){
			s+=a[i]-'a';s1+=b[i]-'a';
		}
		if((s+s1)%2==1) printf("Case #%d: NO\n",kcase++);
		else printf("Case #%d: YES\n",kcase++);
	}
	else{
		int x=a[0]-'a';
		int y=b[0]-'a';
		int x1=a[1]-'a';
		int y1=b[1]-'a';
		int change=(26+y-x)%26;
		if(change%2==0&&(x1+change)%26==y1) printf("Case #%d: YES\n",kcase++);
		else{
			change=(y1-x+26)%26;
			if(change%2==1&&(x1+change)%26==y) printf("Case #%d: YES\n",kcase++);
			else printf("Case #%d: NO\n",kcase++);
		}
	}
	}
}
