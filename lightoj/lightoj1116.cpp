#include<cstdio>  
#include<cstring>  
int main()  
{  
    int t,k=1;  
    long long w,n,m;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%lld",&w);  
        if(w&1)  
            printf("Case %d: Impossible\n",k++);  
        else  
        {  
            for(m=2;m<=w;++m)  
            {  
                if(w%m==0&&((w/m)&1))  
                {  
                    n=w/m;  
                    break;  
                }  
            }  
            printf("Case %d: %lld %lld\n",k++,n,m);  
        }  
    }  
    return 0;  
}   
