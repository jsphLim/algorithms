#include<stdio.h>  
#include<algorithm>
#include<math.h>
using namespace std;
int main(){  
    int T;  
    int a[105];  
    char c;  
    scanf("%d",&T);  
    while (getchar() != '\n');  
    while(T--){  
        int cnt=0;  
        while((c=getchar())!='\n'){  
            if(c>='0' && c<='9'){  
                ungetc(c,stdin); 
                scanf("%d",&a[cnt++]);  
            }  
        }  
        int max=0;  
        for(int i=0;i<cnt-1;i++){  
            for(int j=i+1;j<cnt;j++){  
                int t=__gcd(a[i],a[j]);  
                if(t>max) max=t;  
            }  
        }  
        printf("%d\n",max);  
    }  
    return 0;  
}  
