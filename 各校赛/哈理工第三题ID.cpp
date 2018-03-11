#include<stdio.h>
#include <stdlib.h>
 
long long int a[1000001];
 
int main()
{
    int i, t;
    long long int n;
    int m;
    scanf("%d", &t);
    while(t--)
    {
        m = 0;
        scanf("%lld", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for (i = 0; i < n; i++)
        {
            m=m^a[i];
			        }
        
    }
     printf("%d\n", m);
    return 0;
}
