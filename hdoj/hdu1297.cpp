#include <stdio.h>  
int rrr[1001][1000];  
  
void big_add(int a[],int b[],int c[])  
{  
    int i,len;  
    len=a[0]>b[0]?a[0]:b[0];  
    for(i=1;i<(len+3);i++)  
        c[i]=0;  
    for(i=1;i<=len;i++)  
    {  
        c[i]+=a[i]+b[i];  
        if(c[i]>=10)  
        {  
            c[i]-=10;  
            c[i+1]++;  
        }  
    }  
    if(c[i]>0)  
        len++;  
    c[0]=len;  
      
}  
int main()  
{  
    int x[1000];  
    int n;  
    rrr[1][0]=1;  
    rrr[1][1]=1;  
    rrr[2][0]=1;  
    rrr[2][1]=2;  
    rrr[3][0]=1;  
    rrr[3][1]=4;  
    rrr[4][0]=1;  
    rrr[4][1]=7;  
    int i=5;  
    while(i<=1000)  
    {  
        big_add(rrr[i-4],rrr[i-2],x);  
        big_add(x,rrr[i-1],rrr[i]);  
        i++;  
    }  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(i=rrr[n][0];i>=1;i--)  
        {  
            printf("%d",rrr[n][i]);  
        }  
        printf("\n");  
    }  
    return 0;  
}  
