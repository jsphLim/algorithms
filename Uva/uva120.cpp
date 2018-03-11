#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 35
int a[100], loc[100], n, p, pv, Max;
void Swap(int x)
{
int i, j, t;
for(i = 0, j = x; j > i; j--, i++)
{
   t = a[i];
   a[i] = a[j];
   a[j] = t;
}
}
int main()
{
int i, j;
while(scanf("%d", &a[0]) != EOF)
{
   n = 1;
   while(1)
   {
    if(getchar() != ' ')
     break;
    scanf("%d", &a[n++]);
   }
   printf("%d", a[0]);
   for(i = 1; i < n; i++)
    printf(" %d", a[i]);
   printf("\n");
   pv = 0;
   for(i = 0; i < n; i++)
   {
    for(j = n - i - 1, Max = -10000; j >= 0; j--)
     if(Max < a[j])
     {
      Max = a[j];
      p = j;
     }
    if(p != n - i - 1)
    {
     if(p != 0)
     {
      Swap(p);
      loc[pv++] = n - p;
     }
     Swap(n - i - 1);
     loc[pv++] = i + 1;
    }
   }
   if(pv == 0)
    printf("%d\n", 0);
   else
   {
    for(i = 0; i < pv; i++)
     printf("%d ", loc[i]);
    printf("%d\n", 0);
   }
}
return 0;
}
