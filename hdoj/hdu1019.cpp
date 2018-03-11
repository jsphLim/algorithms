#include<stdio.h> 
int arr[1000000]={0};
int gcd2(int m,int n)
{
	long long int t;
	t=m*n;
       if (m < n)
       {
             int tmp = m;
              m = n;
              n = tmp;
       }
       if (n == 0)
              return m;
      
       while (n > 0)
       {
            int tmp = m % n;
              m = n;
              n = tmp;
       }
       
       return t/m;
}

int main()
{
	int n,i;
	int t; 
	int m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n-1;i++){
			m=gcd2(arr[i],arr[i+1]);
			arr[i+1]=m;
		}
		printf("%d\n",m);
		
	
		
	}
	return 0;
}


/*#include <stdio.h>
#include <string.h>
int gcd(int x, int y)
{
    for(int t; t = x%y; x=y, y=t);
    return y;
}
int main()
{
    int n, i;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int last, now;
        scanf("%d%d", &n, &last);
        for(i=0; i<n-1; i++)
        {
            scanf("%d", &now);
            last *= now/gcd(last, now);
        }
        printf("%d\n", last);
    }
    return 0;
}
