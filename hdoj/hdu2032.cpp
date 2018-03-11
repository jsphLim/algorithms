#include<stdio.h>
int a[100][100];
int  main()
{
	int i, j,n;
	
    while(scanf("%d",&n)!=EOF) {
	for (i = 0; i <n; i++)

		for (j = 0; j <n; j++)
		{
			a[i][0] = 1;
			if (i == j)

				a[i][j] = 1;

		}

	for (i = 2; i <n; i++)
	{
		for (j = 1; j <= i - 1; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}

	for (i = 0; i<n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if(j==n-1)
			printf("%d", a[i][j]);
			else
            printf("%d ", a[i][j]);
		}printf("\n");
	}printf("\n");
}return 0;
}

