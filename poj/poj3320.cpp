#include <cstdio>
#define M 20
int n, Min, a[M][M], b[M][M];
int check(int x, int y)//将其上左右三面的值相加
{
    int sum = 0;
    if(x-1>=0) sum += b[x-1][y];
    if(y-1>=0) sum += b[x][y-1];
    if(y+1<n) sum += b[x][y+1];

    return sum%2;//如果是偶数就返回0，奇数就返回1
}
void dfs(int cur)
{
    //利用深度优先遍历枚举第一行
    if(cur!=n)
    {
        b[0][cur] = 1;
        dfs(cur+1);
        b[0][cur] = 0;
        dfs(cur+1);
    }
    else//枚举完之后开始递推下面每一行的情况
    {
        for(int i = 1; i < n; i++)
            for(int j = 0; j < n; j++)
                b[i][j] = check(i-1,j);
        int cou = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(a[i][j]==1&&b[i][j]==0)
                    return;//题目只能把0变1，不能把1变0，所以直接结束。
                else if(a[i][j]==0&&b[i][j]==1)
                    cou++;//只有当出现原来为0，枚举出的结果中为1的情况，cou才+1
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
        dfs(0);//开始枚举；
        printf("Case %d: ",t);
        if(Min==1e9)
            printf("-1\n");
        else
            printf("%d\n",Min);
    }
    return 0;
}

