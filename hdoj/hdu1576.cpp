#include <stdio.h>    
#include <stdlib.h>    
    
#define m 9973    
int exGcd(int a,int b,int &x,int &y)  
{  
    if(b==0)  
    {  
        x=1;y=0;  
        return a;  
    }  
    int r=exGcd(b,a%b,x,y);  
    int t=x;x=y;y=t-a/b*y;  
    return r;  
}  
    
int main()    
{    
    int n,b,t,x,y;    
    scanf("%d",&t);    
    
    while(t--)    
    {    
        scanf("%d%d",&n,&b);    
        exGcd(b,m,x,y);    
        x=(x%m+m)%m;    
        printf("%d\n",(x*n)%m);    
    }    
    return 0;    
}  
