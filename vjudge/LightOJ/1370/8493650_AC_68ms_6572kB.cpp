#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath> 
using namespace std;
bool isprm[1000005];  
int prm[1000005],cnt=0;  
void init()  
{  
    memset(isprm,1,sizeof(isprm));  
    isprm[0]=isprm[1]=false;  
    for(int i=2; i<1000005; ++i)  
    {  
        if(isprm[i])  
        {  
            for(int j=2*i; j<1000005; j+=i)  
                isprm[j]=false;  
            prm[cnt++]=i;  
        }  
    }  
}  
int main(){
	long long sum,n,t,a;
	cin>>t;
	int kcase=1;
	init();
	while(t--){
		sum=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a);
			for(int k=a+1;;k++){
				if(isprm[k]==1){
					sum+=k;break;
				}
			}
		}
	  printf("Case %d: %lld Xukha\n",kcase++,sum);
	}
}