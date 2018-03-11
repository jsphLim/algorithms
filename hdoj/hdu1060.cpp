#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
int ans[5000005];
void print(){
	int i;
  for(int i=1;i<=500000;i++) ans[i] = 1;
    for(int i=2;i<=250000;i++)
        for(int j=i*2;j<=500000;j+=i)
            ans[j]+=i;
            
}
using namespace std;
int main(){  
    int i,n,t;  
    print();
    scanf("%d",&t);
    while(t--){ 
    scanf("%d",&n);
         
        cout << ans[n] << endl;   
    }  
    return 0;  
} 
