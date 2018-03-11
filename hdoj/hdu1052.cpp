#include <stdio.h>  
#include <algorithm>  
using namespace std;  
int T[1002],K[1002],n,win,lose; 
char a[1002],b[1002]; 
void read()  
{  
    scanf("%s%s",a,b);
    for(int i=0;i<n;i++)  
        K[i]=a[i]-'0';
    for(int i=0;i<n;i++)  
        T[i]=b[i]-'0'; 
    sort(T,T+n);  
    sort(K,K+n);  
}  
void race()  
{  
    win = lose =0;  
    int t_slow=0,t_fast=n-1;  
    int k_slow=0,k_fast=n-1;  
    while(t_slow <= t_fast)  
    {  
        if(T[t_slow] > K[k_slow])        //情况1  
        {  
            win++;  
            t_slow++;  
            k_slow++;  
        }  
        else if(T[t_slow] < K[k_slow])   //情况2  
        {  
            lose++;  
            t_slow++;  
            k_fast--;  
        }  
        else                             //情况3  
        {  
            if(T[t_fast] > K[k_fast])    //先别放水，让哥比完这场  
            {  
                win++;  
                t_fast--;  
                k_fast--;  
            }  
            else                         //1、2、3、放  
            {  
                if(T[t_slow] < K[k_fast])//不一定会输
                    lose++;  
                t_slow++;  
                k_fast--;  
            }  
        }  
    }  
}  
int main()  
{  
    //freopen("1","r",stdin);  
    //freopen("2","w",stdout);  
        scanf("%d",&n);   
        read();  
        race();  
        if(win-lose>=0) {
        	printf("%d\n",lose);
			printf("%d\n",win);  
		}
        else{
        	printf("%d\n",abs(lose));
            printf("%d\n",win);
  }
    return 0;  
}  
