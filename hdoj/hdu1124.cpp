#include <bits/stdc++.h>
using namespace std;  
long long CalZeroNum(long long n)  
{  
    long long num=0;//n!结尾零的个数  
    int b=1;//5的次方  
    while(1)  
    {  
        b*=5;  
        num+=n/b;  
        if(b>n)  
            break;  
    }  
    return num;//返回结尾零的个数  
}  
int main()  
{  
    int n;
    cin>>n;
    long long k;
    while(n--){
    	scanf("%lld",&k);
    	cout<<CalZeroNum(k)<<endl;
	}
}  
