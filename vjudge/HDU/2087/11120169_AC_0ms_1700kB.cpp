#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{  
    string a;  
    int ans;
    while(cin>>a)
    {
         
        if(a=="#")
            break;
        char b[1009];
        cin>>b;
        ans=0;
        while(a.find(b)!=string::npos)//直到找不到子字符串则退出循环
        {
            a.erase(a.find(b),strlen(b));//第一个参数返回值为找到子字符串的开头第一个字母的下标，第二个参数是子字符串的长度
            ans++;//刚好可以利用这俩参数真正做到从 a 中“剪掉”花布条 b
        }
        cout<<ans<<endl;
    }
    return 0;
}