#include<iostream>
using namespace std;
int main()
{
    char a,b,t;
    int n,i,j;
    char str[90][90];
    int r=0;
    while(cin>>n>>a>>b)
    {
        if(r++)
            cout<<endl;
        if(n==1)
        {
            cout<<a<<endl;
            continue;
        }
        if(n%4==1)
            t=a,a=b,b=t;
        for(i=0;i<n;i++)
            str[0][i]=b;
        for(i=1;i<=n/2;i++)
        {
            memcpy(str[i],str[i-1],sizeof(str[i-1]));
            for(j=i;j<n-i;j++)
                if(i%2==0)
                    str[i][j]=b;
                else
                    str[i][j]=a;
        }
        str[0][0]=str[0][n-1]=' ';
        for(i=0;i<=n/2;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<str[i][j];
            }
            cout<<endl;
        }
        for(i=n/2-1;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                cout<<str[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
