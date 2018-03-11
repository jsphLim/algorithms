#include<stdio.h>
#include<string.h>
int main()
{
	char a[300],b[300];
	int data[300];
	int lena,lenb,car,i,tem,num,j,flag;
	while(scanf("%s%s",a,b)!=EOF)
	{
		lena=strlen(a);
		lenb=strlen(b);
		car=0;
		num=0;
		for(i=lena-1,j=lenb-1;i>=0||j>=0||car;)
		{
			tem=0;
			if(i>=0)
			{
				tem+=a[i]-'A';
			}
			if(j>=0)
			{
				tem+=b[j]-'A';
			}
			tem+=car;
			data[num++]=tem%26;
			car=tem/26;
			if(i>=0)
				i--;
			if(j>=0)
				j--;
		}
		flag=1;
		for(i=num-1;i>=0;i--)
		{
			if(data[i]==0&&flag)
			{
				continue;
			}
			flag=0;
			printf("%c",data[i]+'A');
		}
		if(flag)
			printf("A");
		puts("");
	}
	return 0;
}

