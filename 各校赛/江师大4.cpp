#include<stdio.h>
int arr[10000];
int gcd(int a,int b)     //�����Լ������
{
     if (a%b==0) return b;
       else return gcd(b,a%b);      //շת�����
}

int lcm(int a,int b)       //����С��Լ������
{
      int x;
      x=gcd(a,b);      //����gcd()����
      return a*b/x;
}

int main(){
	int n,m,t;
	int i;
	
	while(scanf("%d",&t)!=EOF){
		for(i=0;i<t;i++){
			scanf("%d",&arr[i]);
		}
		for(i=0;i<t-1;i++){
			m=arr[i];
			n=arr[i+1];
			arr[i+1]=lcm(m,n);
		}
		printf("%d\n",arr[t-1]);
	}
}