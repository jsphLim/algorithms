#include<bits/stdc++.h>
using namespace std;
int prime[100000005]; 
void init_prime()  
{  
    int i, j;  
    for(i = 2;i <= sqrt(1000002.0); ++i)  
    {  
        if(!prime[i])  
            for(j = i * i; j < 1000002; j += i)  
                prime[j] = 1;  
    }  
}  
bool pri(int x){
	
}
int main(){
	int sum,m,t;
	cin>>t;
	while(t--){
	  while(cin>>sum>>m){
     	
	 }
	}
	  
}
