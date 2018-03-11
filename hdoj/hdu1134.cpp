/*
卡特兰计算公式：
数列 a[n]=C(2n,n)/(n+1)
为了计算的方便将其推导为递推公式：a[n]=((4*n-2)/(n+1))*a[n-1];
卡特兰数实质：h(n)= h(0)*h(n-1)+h(1)*h(n-2) + … + h(n-1)h(0) (其中n>=2)
卡特兰数模型：
1.出栈次序问题
一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列?
2.凸多边形的三角剖分问题
　 求将一个凸多边形区域分成三角形区域的方法数。
3.用给定节点组成二叉树的问题
（能构成h（N）个）

#include <iostream>
#include <cstring>
using namespace std;

long long ans[105];//仍然溢出 

void init()
{
     int i,j,k;
     ans[1] = 1,ans[2] = 2,ans[3] = 5;
     for(i=4;i<=100;i++)
          ans[i] = ((4*i-2)/(i+1))*ans[i-1];
}

int main()
{
     int i,j,k;
     int num;
     init();
     while(cin>>num,~num)
          cout<<ans[num]<<endl;
     return 0;
}*/
#include <iostream>
using namespace std;

const int SIZE = 100;

int main()
{
    int ans[101][SIZE]={0}; //数组用来存放结果
    ans[1][0]=1;            //初始化第一项            
    int i,j,r=0,temp=0,len=1;    //len 表示当前最长的有效位数，初始为1
    for(i=2;i<=100;i++)          //从第二项到第100项，用公式计算
    {
        for(j=0;j<len;j++)   //---------------乘法部分------------------
        {
            ans[i][j]=ans[i-1][j]*(4*i-2);    //乘法从低位到高位
        }
        for(j=0;j<len;j++)        //对乘出的结果进行处理，不包括最高位
        {
            temp=ans[i][j]+r;
            ans[i][j]=temp%10;
            r=temp/10;
        }
        while(r)            //对最高位进位处理 
        {
            ans[i][len]=r%10;
            r/=10;
            len++;
        }            
        //除法部分
        for(j=len-1,r=0;j>=0;j--)
        {            //除法从高位到低位
            temp=r*10+ans[i][j];
            ans[i][j]=temp/(i+1);
            r=temp%(i+1);
        }
        while(!ans[i][len-1])        //处理高位的零位
            len--;

    }          
    int n;
    while(cin>>n&&n!=-1)
    {
        for(i=SIZE-1;!ans[n][i];i--);
        for(i;i>=0;i--)
            cout<<ans[n][i];
        cout<<endl;
    }
    return 0;
}
