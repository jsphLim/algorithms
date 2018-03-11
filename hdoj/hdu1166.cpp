#include<bits/stdc++.h>
using namespace std;
int main()  
{  
    char a[1000];  
    int i,m,len,vis[1000]; 
    while(scanf("%s",a)!=EOF)  
    {  
        memset(vis,0,sizeof(vis));
        len=strlen(a); 
		i=0;
        while(a[i]=='5') i++;
        m=0;
        while(i<len)
        {  
            if(a[i]!='5')  
              {  
            vis[m]=vis[m]*10+a[i]-'0';   
              }  
            else if(a[i]=='5'&&a[i+1]!='5'&&a[i+1]!='\0')
              m++;
              i++;
        }
		  sort(vis,vis+m+1);
		  for(i=0;i<m;i++)cout<<vis[i]<<" ";
		  cout<<vis[m]<<endl;
    }
}
