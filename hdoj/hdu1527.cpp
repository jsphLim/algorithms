#include<stdio.h>
#include<math.h>
int  main ()
{
   int n,m,k,t;
   while(~scanf("%d%d",&n,&m))
   {  
       if(n==0&&m==0) break;
       if(n<m)
       {
              t=m;
              m=n;
              n=t;
       }
       k=n-m;
       if(int(k*(1+sqrt(5.0))/2)==m) 
       printf("0\n");
       else{
       	 printf("1\n");
       	for(int i=0;i<=n;i++)
       	    {
       	    	if(i<j) {
       	    		int u=j-i;
       	    		if(int(u*(1+sqrt(5.0))/2)==i) printf("%d %d\n",i,j);
				   }
				   else{
				   	int u=i-j;
				   	if(int(u*(1+sqrt(5.0))/2)==j) printf("%d %d\n",j,i);
				   }
       	    	
			}
       	
       	
       	
	   }
      
    }
    return 0;
}
