#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int n,j;
int i;
int main(){
	while(cin>>n){
		for(j=0;j<n;j++){
		scanf("%d",&ar[j]);
	}
	for(i='A';i<='Z';i++){
	   for(j=0;j<n;j++)
	   	if((ar[j]^i)>'Z'||(ar[j]^i)<'A') break;
	   	if(j>n-1)
		    break;
   }
	   for(j=0;j<n;j++) printf("%c",i^ar[j]);
	cout<<endl;
	}
}
