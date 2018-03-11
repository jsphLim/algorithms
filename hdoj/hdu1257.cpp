
#include<stdio.h>
int main()
{
    int i,j,n,a[10000],temp,count;
    while(scanf("%d",&n)!=EOF)
    {
        
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        count=0;
        for(i=i-1;i>=0;i--)
        {
            if(a[i]){temp=a[i];count++;}
            else{continue;}
            for(j=i-1;j>=0;j--)
            {
                if(a[j]>=temp){temp=a[j];a[j]=0;}
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
