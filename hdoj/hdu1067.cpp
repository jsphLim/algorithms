#include<stdio.h>
#include<string.h>
int main()
{
    int l;
    char arr[1000]={0};
    char brr[1000]={0};
	while(1)
	{
    scanf("%s",arr);
   strcpy(brr,arr);
   strrev(brr);
    if(strcmp(arr,brr)==0)
        printf("Yes");
    else
        printf("No");
	}
    return 0;


}
