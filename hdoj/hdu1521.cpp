#include <bits/stdc++.h>
using namespace std;
int jcs[15];  
int main ()  
{  
    jcs[0]=1;  
    for(int i=1;i<=12;i++)  
        jcs[i]=jcs[i-1]*i;  
    double c1[15],c2[15];  
    int c[15];  
    int m,n,i,j,k;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        for(i=1;i<=n;i++)  
            scanf("%d",&c[i]);  
        for(i=0;i<=n;i++)  
        {  
            c1[i]=c2[i]=0;  
        }  
        c1[0]=1.0/jcs[0];  
        for(i=1;i<=n;i++)  
        {  
            for(j=0;j<=m;j++)  
                for(k=0;k+j<=m&&k<=c[i];k++)  
                    c2[k+j]+=c1[j]/jcs[k];  
            for(j=0;j<=m;j++)  
                c1[j]=c2[j],c2[j]=0;  
        }  
        printf("%.0f\n",c1[m]*jcs[m]);  
    }  
    return 0;  
}  
