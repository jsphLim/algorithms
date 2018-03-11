#include<stdio.h>
main()
{
    int a,b,c;
    while(~scanf("%d%d",&a,&b))
    {
        b%=4;a%=10;c=a;
        if(b==0)
        b=4;
        while(--b)
        c=c*a%10;
        printf("%d\n",c);
    }
}
