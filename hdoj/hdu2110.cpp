#include<bits/stdc++.h>
using namespace std;
int c1[2000000],c2[2000000];
int num[205];
int v[205];
int main(){
	int n;
	while(cin>>n,n){
	   int sum=0,a,b;
	   int u=0;
	   for(int i=1;i<=n;i++){
	   	scanf("%d%d",&v[i],&num[i]);
	   	sum+=v[i]*num[i];
	   }
	   if(sum%3) cout<<"sorry"<<endl;
	   else{
	   	memset(c1,0,sizeof(c1));
	   	memset(c2,0,sizeof(c2));
	   	  for(int i=0;i<=num[1]*v[1]&&i<=sum/3;i+=v[1])
	   	  c1[i]=1;
	   	  
	   	  for(int i=2;i<=n;i++){
	   	  	for(int j=0;j<=sum/3;j++)
	   	  		for(int k=0;k<=num[i]*v[i]&&k+j<=sum/3;k+=v[i]){
	   	  		c2[j+k]+=c1[j];
				c2[j+k]%=10000;	
			 }
			 for(int j=0;j<=sum/3;j++){
			 	c1[j]=c2[j]%10000;
			 	c2[j]=0;
			 }
	   }
	   if(c1[sum/3])
	   cout<<c1[sum/3]%10000<<endl;
	   else cout<<"sorry"<<endl;
	}
}
}
