#include<bits/stdc++.h>
using namespace std;
#define maxn 100005    
int dp[maxn],a[105],c;  
int    main(){  
    int n,m;  
    while(cin>>n>>m){  
        if(n==0 || m==0) break;  
        memset(dp,0,sizeof(dp));  
        for(int i=1;i<=n;i++)                               
            scanf("%d",&a[i]);  
        for(int i=1;i<=n;i++){                    //��Ʒ��������  
            scanf("%d",&c);  
            if(m<c*a[i]){                              //�ж��Ƿ���Ե�����ȫ�������������������Ʒ���������>=����  
                for(int k=0;k<=m;k++)          //��ȫ����  
                    if(k>=a[i])  
                        dp[k]=max(dp[k],dp[k-a[i]]+a[i]);  
            }  
            else{  
            for(int j=1;j<=c;j<<=1){            //�ֶѹ���  
                for(int k=m;k>=0;k--)           //һ����ѯ��2^j��01����  
                    if(k>=a[i]*j)  
                        dp[k]=max(dp[k],dp[k-a[i]*j]+a[i]*j);  
                c-=j;  
            }  
            if(c>0){                                      //С�Ż����ڣ�����һ��������Լ����  
                for(int k=m;k>=0;k--)  
                    if(k>=a[i]*c)  
                        dp[k]=max(dp[k],dp[k-a[i]*c]+a[i]*c);  
            }  
        }  
        }  
        int ans=0;  
        for(int i=1;i<=m;i++){  
            if(dp[i]==i)  
                ans++;  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
} 

