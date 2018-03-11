#include <cstdio>
#define M 20
int n, Min, a[M][M], b[M][M];
int check(int x, int y)//���������������ֵ���
{
    int sum = 0;
    if(x-1>=0) sum += b[x-1][y];
    if(y-1>=0) sum += b[x][y-1];
    if(y+1<n) sum += b[x][y+1];

    return sum%2;//�����ż���ͷ���0�������ͷ���1
}
void dfs(int cur)
{
    //����������ȱ���ö�ٵ�һ��
    if(cur!=n)
    {
        b[0][cur] = 1;
        dfs(cur+1);
        b[0][cur] = 0;
        dfs(cur+1);
    }
    else//ö����֮��ʼ��������ÿһ�е����
    {
        for(int i = 1; i < n; i++)
            for(int j = 0; j < n; j++)
                b[i][j] = check(i-1,j);
        int cou = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(a[i][j]==1&&b[i][j]==0)
                    return;//��Ŀֻ�ܰ�0��1�����ܰ�1��0������ֱ�ӽ�����
                else if(a[i][j]==0&&b[i][j]==1)
                    cou++;//ֻ�е�����ԭ��Ϊ0��ö�ٳ��Ľ����Ϊ1�������cou��+1
        if(Min>cou)
            Min = cou;
        return;
    }
}
int main ()
{
    int cas, t = 0;
    scanf("%d",&cas);
    while(t++<cas)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&a[i][j]);

        Min = 1e9;
        dfs(0);//��ʼö�٣�
        printf("Case %d: ",t);
        if(Min==1e9)
            printf("-1\n");
        else
            printf("%d\n",Min);
    }
    return 0;
}

