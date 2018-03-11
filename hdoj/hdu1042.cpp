#include<stdio.h>
#include<string.h>
#define M 36000
int main()
{
    int a[M],i,j,t,k,l,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));     
        a[0]=1;             
        for(i=2;i<=n;i++)
         {
             k=0;
             for(j=0;j<M;j++)
             {
                 t=a[j]*i+k;
                 k=t/10;
                 a[j]=t%10;
             }
         }
         for(i=M-1;;i--)
          {
              if(a[i]!=0)
              {
               l=i;
               break;  
              }
          }
          for(i=l;i>=0;i--)
           printf("%d",a[i]);
         printf("\n");
        
    }
    return 0;
}
