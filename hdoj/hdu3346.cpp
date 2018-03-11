#include<bits/stdc++.h>
using namespace std;
char ss[100];
bool lucky1(int x){
	
}
int main(){
	int n;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%8==0) {
		cout<<"Lucky number!"<<endl;
		continue;	
		}
		sprintf(ss,"%d",n);
		int len=strlen(ss);
		int sum1=0,sum2=0;
		for(int i=0;i<len;i++){
			sum1+=ss[i];
			sum2+=ss[i]*ss[i];
		}
		if(sum1%8==0||sum2%8==0) cout<<"Lucky number!"<<endl;
		else cout<<"What a pity!"<<endl;
	}
}
