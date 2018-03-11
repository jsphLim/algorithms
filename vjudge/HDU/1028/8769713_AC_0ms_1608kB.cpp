#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
const int maxn = 3000;
int c1[maxn],c2[maxn];
int main(){
	for(int i=0;i<=400;i++){
		c1[i]=1;
		c2[i]=0;
	}
	for(int i=2;i<=300;i++){
			for(int j=0;j<=3050;j++)
			for(int k=0;k<=305-j;k+=i){
				c2[j+k]+=c1[j];
			}
	for(int j=0;j<=305;j++){
		c1[j]=c2[j];
		c2[j]=0;
	}
}
	int n;
	while(cin>>n){
		cout<<c1[n]<<endl;
	}
}