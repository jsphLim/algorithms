#include<stdio.h>
int a[6000];
int min(int n,int m){
	return n>m?m:n;
}
int main(){
    int p1=1;
	int p2=1;
	int p3=1;
	int p4=1;
    int i=0;
    a[1]=1;
    int k=1; 
	while(k<5900){
    a[++k]=min(min(2*a[p1],3*a[p2]),min(5*a[p3],7*a[p4]));
    if(a[k]==2*a[p1]) p1++;
    if(a[k]==3*a[p2]) p2++;
    if(a[k]==5*a[p3]) p3++;
    if(a[k]==7*a[p4]) p4++;
}
   
	int n;
	while(scanf("%d",&n)&&n){
	printf("The ");
		if(n%10==1&&n%100!=11)printf("%dst",n);
		else if(n%10==2&&n%100!=12)printf("%dnd",n);
		else if(n%10==3&&n%100!=13)printf("%drd",n);
		else printf("%dth",n);

		printf(" humble number is %lld.\n",a[n]);
	}
}
/*
���ȣ���һ������Ϊ��1���������ÿһ������������ǰһ��������2��3��5��7������
��ô��һ����������ǰһ�������ĸ����õ�����Сֵ��for example����һ����1���ڶ�����1*2��1*3��1*5��1*7��
��ȻΪ2����������2*2,1*3,1*5��1*7����Ȼ��3�����ĸ���2*2,,2*3,1*5,1*7Ϊ4���������3*2,2*3,1*5,1*7����   ���������Ƿ��������أ�
*/





