#include<iostream>
using namespace std;
int modexp_simple(int a,int b,int n)       
{      
    int ret = 1;  
    while (b--)  
    {  
        ret = a * ret % n;  
    }  
    return ret;  
}    
int main(){
	int n;
	while(scanf("%d",&n),n){
		if(modexp_simple(n,n,9)==0) cout<<9<<endl;
		else
		cout<<modexp_simple(n,n,9)<<endl;
	}
}
