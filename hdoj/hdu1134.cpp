/*
���������㹫ʽ��
���� a[n]=C(2n,n)/(n+1)
Ϊ�˼���ķ��㽫���Ƶ�Ϊ���ƹ�ʽ��a[n]=((4*n-2)/(n+1))*a[n-1];
��������ʵ�ʣ�h(n)= h(0)*h(n-1)+h(1)*h(n-2) + �� + h(n-1)h(0) (����n>=2)
��������ģ�ͣ�
1.��ջ��������
һ��ջ(�����)�Ľ�ջ����Ϊ1��2��3������n���ж��ٸ���ͬ�ĳ�ջ����?
2.͹����ε������ʷ�����
�� ��һ��͹���������ֳ�����������ķ�������
3.�ø����ڵ���ɶ�����������
���ܹ���h��N������

#include <iostream>
#include <cstring>
using namespace std;

long long ans[105];//��Ȼ��� 

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
    int ans[101][SIZE]={0}; //����������Ž��
    ans[1][0]=1;            //��ʼ����һ��            
    int i,j,r=0,temp=0,len=1;    //len ��ʾ��ǰ�����Чλ������ʼΪ1
    for(i=2;i<=100;i++)          //�ӵڶ����100��ù�ʽ����
    {
        for(j=0;j<len;j++)   //---------------�˷�����------------------
        {
            ans[i][j]=ans[i-1][j]*(4*i-2);    //�˷��ӵ�λ����λ
        }
        for(j=0;j<len;j++)        //�Գ˳��Ľ�����д������������λ
        {
            temp=ans[i][j]+r;
            ans[i][j]=temp%10;
            r=temp/10;
        }
        while(r)            //�����λ��λ���� 
        {
            ans[i][len]=r%10;
            r/=10;
            len++;
        }            
        //��������
        for(j=len-1,r=0;j>=0;j--)
        {            //�����Ӹ�λ����λ
            temp=r*10+ans[i][j];
            ans[i][j]=temp/(i+1);
            r=temp%(i+1);
        }
        while(!ans[i][len-1])        //�����λ����λ
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
