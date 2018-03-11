#include<bits/stdc++.h>
using namespace std;
char s[1000];
double sum=0,sums=0;
int main(){
	int t,m;
	cin>>t;
	double sc,cr;
	while(t--){
		cin>>m;
		sum=0;
		sums=0;
		int flag=0;
		for(int i=0;i<m;i++){
			scanf("%s",s);
			scanf("%lf",&cr);
			scanf("%lf",&sc);
			if(sc<60) flag=1;
			sum+=cr*sc;
			sums+=cr;
		}
		if(flag) cout<<"Sorry!"<<endl;
		else printf("%.2lf\n",1.0*sum/sums);
		if(t!=0) cout<<endl;
	}
}
