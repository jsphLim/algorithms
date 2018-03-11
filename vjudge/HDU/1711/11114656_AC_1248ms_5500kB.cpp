#include<stdio.h>
int a[1000010],b[10010];
int next[10010];
int n,m;
void getNext()
{
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while(j<m)
    {
        if(k==-1||b[j]==b[k])
          next[++j]=++k;
        else k=next[k];
    }    
}  
//返回首次出现的位置 
int KMP_Index()
{
    int i=0,j=0;
    getNext();
    
    while(i<n && j<m)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;
            j++;
        }    
        else j=next[j];
        
    }    
    if(j==m) return i-m+1;
    else return -1;
}      
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
          scanf("%d",&b[i]);
        printf("%d\n",KMP_Index());
    }    
    return 0;
}