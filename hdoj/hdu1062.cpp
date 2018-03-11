#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int t,n,i,j,k,m;
	scanf("%d ",&t);
	while(t--)
	{
		j=1;
		int b[1000];
		b[0]=-1;
		gets(a);
		n=strlen(a);
		m=0;
		for(i=0;i<n;i++)
		{
			
			if(a[i]==' '){
				for(j=i-1;j>=m;j--) printf("%c",a[j]);
				m=i+1;
				printf(" ");
			}
	    	
		}
	    for(i=n-1;;i--){
	    	if(a[i]==' ') break;
	    	else{
	    		printf("%c",a[i]);
			}
		}
		printf("\n");
	}
}
