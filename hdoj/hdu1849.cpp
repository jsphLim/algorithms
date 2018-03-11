#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,u;
	while(cin>>n,n){
		ans=0;
		for(int i=0;i<n;i++){
			cin>>u;
			ans^=u;
		}
		if(ans) printf("Rabbit Win!\n");
		else printf("Grass Win!\n");
	}
}
