#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,s,f,m,s2,f2,m2;
	int st,ft,mt;
	cin>>t;
	while(t--){
	   cin>>s>>f>>m>>s2>>f2>>m2;
		st=s+s2;
		ft=f+f2;
		mt=m+m2;
			if(mt>=60){
			mt-=60;
			ft++;
		}
		if(ft>=60){
			ft-=60;
			st++;
		}
		cout<<st<<" "<<ft<<" "<<mt<<endl;
	}
}
