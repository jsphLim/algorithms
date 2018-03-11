#include<stdio.h>
int arr[10000];
int gcd(int a,int b)     //求最大公约数函数
{
     if (a%b==0) return b;
       else return gcd(b,a%b);      //辗转相除法
}

int lcm(int a,int b)       //求最小公约数函数
{
      int x;
      x=gcd(a,b);      //调用gcd()函数
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