#include<iostream>
#include<string.h>
const int MAX=100;
using namespace std;
int a[MAX],b[MAX],v[MAX]; 
int n1[MAX],n2[MAX]; 
//��ʼ��a
int main(){
 int t;
 cin>>t;
 while(t--){ 
 	memset(n2,0,sizeof(n2));
 	for(int i=0;i<26;i++) {
 		cin>>n2[i];
 		v[i]=i+1;
	 }
a[0]=1;  
int last=0;  
for (int i=0;i<26;i++)  
{  
    int last2=min(last+n2[i]*v[i],50);//������һ�ε�last  
    memset(b,0,sizeof(int)*(last2+1));//ֻ���b[0..last2]  
    for (int j=0;j<=n2[i]&&j*v[i]<=last2;j++)//������last2  
        for (int k=0;k<=last&&k+j*v[i]<=last2;k++)//����һ����last��һ����last2  
            b[k+j*v[i]]+=a[k];  
    memcpy(a,b,sizeof(int)*(last2+1));//b��ֵ��a��ֻ��ֵ0..last2  
    last=last2;//����last  
}  
int sum=0;
for(int i=1;i<=50;i++) if(a[i])sum+=a[i];
cout<<sum<<endl;
}
}
