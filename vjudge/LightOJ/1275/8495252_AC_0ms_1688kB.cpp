#include <iostream>  
#include<stdio.h>
using namespace std;  
  
int main() {  
    int t;  
    double n, c;  
    scanf("%d", &t);  
    int cnt = 0;  
    while (t--) {  
        scanf("%lf%lf", &n, &c);  
        if(n == 0){  
            printf("Case %d: 0\n", ++cnt); continue;  
        }  
        long long ans = c/(2*n);  
  
        if (ans*(c-ans*n) < (ans+1)*(c-(ans+1)*n))  
            ans++;  
        printf("Case %d: %lld\n", ++cnt, ans);  
    }  
    return 0;  
}  