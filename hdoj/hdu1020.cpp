#include<stdio.h>
int main()
{
	int i,c,t;
	char s[10001];
	scanf("%d ",&t);
	while(t--)
	{
		gets(s); 
		for(i=0;s[i];i++)
		{
			c=1;
			while(s[i]==s[i+1])
				c++,i++;
			if(c!=1)printf("%d%c",c,s[i]);
			else printf("%c",s[i]);
		}
		puts("");
	}
	return 0;
}
