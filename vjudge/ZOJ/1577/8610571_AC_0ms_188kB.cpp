#include<stdio.h>  
#include<algorithm>  
  
using namespace std;  
  
int prime[1100];  
bool flag[1100];  
  
void init()  
{  
    int i,j,num=0;  
    for(i=2;i<1100;i++)  
    {  
        if(!flag[i])  
        {  
            prime[num++]=i;  
            for(j=i*i;j<1100;j=j+i)  
                flag[j]=true;  
        }  
    }  
}  
  
void swap(int &a,int &b)  
{  
    int temp;  
    temp=a;  
    a=b;  
    b=temp;  
}  
  
int power(int n)  
{  
    int i,s=1;  
    for(i=1;i<=n;i++)  
        s=s*2;  
    return s;  
}  
  
void slove(int n)  
{  
    int i,ans=0;  
    for(i=0;prime[i]*prime[i]<=n;i++)  
    {  
        if(n%prime[i]==0)  
        {  
            ans++;  
            n=n/prime[i];  
            while(n%prime[i]==0)  
                n=n/prime[i];  
        }  
        if(n==1)  
            break;  
    }  
    if(n>1)  
        ans++;  
    printf("%d\n",power(ans));  
}  
  
int main()  
{  
    int x,y,n;  
    init();  
    while(scanf("%d%d",&x,&y)!=EOF)  
    {  
        if(y%x!=0)  
        {  
            printf("0\n");  
            continue;  
        }  
        n=y/x;  
        slove(n);  
    }  
    return 0;  
}