#include<bits/stdc++.h>
using namespace std;
int main(){
	string str,s;
	while(cin>>str&&str[0]!='#'){
		cin>>s;
		int sum=0;
		int vis=0;
		while(1){
			vis=str.find(s,vis);
			if(vis<str.length()){
				vis+=s.length() ;
			sum++;
			}
		    else break;
		}
		cout<<sum<<endl;
	}
}
