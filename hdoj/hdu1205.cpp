#include <iostream>  
using namespace std;  
  
int main()  
{  
 int ncases;  
 scanf("%d",&ncases);  
  
 while(ncases--)  
 {  
   long long maxvalue=-1,sweetkinds,sum=0;  
  scanf("%lld",&sweetkinds);  
  
   long long i,n;  
  for(i=0;i<sweetkinds;i++)  
  {  
   scanf("%lld",&n);  
   sum+=n;  
   if(maxvalue<n)  
    maxvalue=n;  
  }  
  if((sum-maxvalue)>=(maxvalue-1))  
   printf("Yes\n");  
  else  
   printf("No\n");  
 }  
 return 0;  
}  
