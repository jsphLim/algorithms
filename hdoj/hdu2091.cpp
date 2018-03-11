#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int m,i,j,f=0;
	char n;
	while(cin>>n){
	if(n=='@') break;
	if(f!=0) cout<<endl;
	f++;
	cin>>m;
	for(i=0;i<m;i++){
		for(j=1;j<=2*m-1;j++){
			if(j==m+i||j==m-i||i==m-1) cout<<n;
			else cout<<" ";
		}
		cout<<endl;
	}
}
}
