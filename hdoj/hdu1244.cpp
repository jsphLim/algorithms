#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int a[1005],b[1005],dp[1005][1005],num[1005];
int main()
{
    int m,n;
    while(~scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
           scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
           scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++)
            num[i]=num[i-1]+a[i];//��¼ǰi�εĺͣ�
        for(int i=1;i<=n;i++)//��ʾ�ж��ٸ�������β������
           for(int j=1;j<=m;j++)//��ʾ�ֳɼ���
           {
               dp[i][j]=dp[i-1][j];//��i������b[j]ʱֱ��ȡ����i-1��Ԫ�طֳ�j�εĽ��
               if(i>=b[j])
                  dp[i][j]=max(dp[i-1][j],dp[i-b[j]][j-1]+num[i]-num[i-b[j]]);/*�ڣ�1��i-1��Ԫ����ȥj�κͣ�2��i-b[j]��Ԫ��ȡj+1���ټ���*/  //����˼�� ȡ���߲�ȡ 

           }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

