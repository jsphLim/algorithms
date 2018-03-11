#include<bits/stdc++.h>
using namespace std;
int main(){//学会画PN表找规律啊 
	int n,m;
	while(scanf("%d%d",&n,&m)&&n+m){
		if(n%2==1&&m%2==1) cout<<"What a pity!"<<endl;
		else cout<<"Wonderful!"<<endl;
	}
}
