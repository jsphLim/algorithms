#include <bits/stdc++.h>
using namespace std;  
long long CalZeroNum(long long n)  
{  
    long long num=0;//n!��β��ĸ���  
    int b=1;//5�Ĵη�  
    while(1)  
    {  
        b*=5;  
        num+=n/b;  
        if(b>n)  
            break;  
    }  
    return num;//���ؽ�β��ĸ���  
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
