#include <bits/stdc++.h>
using namespace std;  
int k[100]={20,72,72,56,60,12,92,56,0,52,12,56,40,92,32,56,80,32,52,56};
int main ()  
{   long long n,m;
    while(cin>>n,n){
    	int kcase=1;
    	for(int i=0;i<n;i++){
    		cin>>m;
    	    if(m==1) {
    	    	printf("Case %d: ",kcase++);
    	    	cout<<2<<endl;
			}
			else if(m==2) {
				printf("Case %d: ",kcase++);
			cout<<6<<endl;	
			}
			else{
				printf("Case %d: ",kcase++);
				cout<<k[(m-3)%20]<<endl;
		}
		}
		cout<<endl; 
	}
} 
