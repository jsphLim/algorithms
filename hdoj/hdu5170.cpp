#include<stdio.h>    
#include<math.h>  
const double eps = 1e-8;  
double a,b,c,d;  
int main()  
{  
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)  
    {  
        double tmp1 = b * log(a);  
        double tmp2 = d * log(c);  
        if(tmp1 - tmp2 > eps)  
            printf(">\n");  
        else if(tmp2 - tmp1 > eps)  
            printf("<\n");  
        else printf("=\n");  
    }  
    return 0;  
}  
