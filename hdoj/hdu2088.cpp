#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	int n,sum=0;
	int f=0;
	while(scanf("%d",&n)&&n){
	
		sum=0;
		for(int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			sum+=a[i];
		}
	int avr=sum/n;
	int ans=0;	
	if(f==1) cout<<endl;
	else f=1;
	for(int i=0;i<n;i++){
		if(a[i]<avr) ans=ans+(avr-a[i]);
	}

	cout<<ans<<endl;
}
}
