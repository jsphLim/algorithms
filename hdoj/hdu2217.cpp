#include <iostream>  
#include<stdio.h>  
#include<algorithm>  
using namespace std;  
int n,T,a[2005];  
int main()  
{  
    int s,q,p,ma,x,y;  
    while(scanf("%d %d",&n,&T)!=EOF)  
    {  
        a[0]=0;  
        for(int i=1; i<=n; i++)  
            scanf("%d",&a[i]);  
        sort(a,a+n+1);
        s=lower_bound(a,a+n+1,0)-a;
        ma=0;  
        for(q=s;q>=0;q--)//qÊÇÍù×ó  
        {  
            for(p=s;p<=n;p++)//pÊÇÍùÓÒ  
            {  
                x=-a[q],y=a[p];  
                if(2*x+y<=T&&p-q>ma) ma=p-q;//×óÓÒ  
                if(2*y+x<=T&&p-q>ma) ma=p-q;//ÓÒ×ó  
            }  
        }  
        cout<<ma<<endl;  
    }  
    return 0;  
}
