#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
bool cmp1(char x,char y){
	return x-'0'>y-'0';
}
int main(){
	char s[100];
	int a[100];
	int n,flag,i,j,k,h,q;
	while(scanf("%d%s",&n,s)){
		if(n==0&&strcmp(s,"END")==0){
			break;
		} 
		flag=0;
		int len=strlen(s);
		for(i=0;i<len;i++){
			a[i]=s[i]-64;
		}
		sort(a,a+len,cmp);
		sort(s,s+len,cmp1);
		for(i=0;i<len;i++){
	   if(flag) break;
		for(j=0;j<len;j++){
		if(flag) break;
		if(a[i]!=a[j])
		for(k=0;k<len;k++){
			if(flag) break;
			if(a[i]!=a[k]&&a[j]!=a[k])
		for(h=0;h<len;h++){
			if(flag) break;
			if(a[i]!=a[h]&&a[j]!=a[h]&&a[k]!=a[h])
		for(q=0;q<len;q++){
			if(a[i]-a[j]*a[j]+a[k]*a[k]*a[k]-a[h]*a[h]*a[h]*a[h]+a[q]*a[q]*a[q]*a[q]*a[q]==n&&a[i]!=a[q]&&a[j]!=a[q]&&a[k]!=a[q]&&a[h]!=a[q]){
				cout<<s[i]<<s[j]<<s[k]<<s[h]<<s[q]<<endl;
				flag=1;break;
          }
      }
  }
}
}
}   
if(flag==0) cout<<"no solution"<<endl;
}
}
