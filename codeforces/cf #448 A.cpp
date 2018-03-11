#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
   int n,x,k;
   cin>>n>>x>>k;
   for(int i=0;i<n;i++) scanf("%d",&a[i]);
   int counts=0;
   for(int i=0;i<n;i++){
   	  if(i+k>=n) break;
   	  int j=i+k;
   	  if(a[j]>a[i]) continue;
   	  int flag=0;
   	  for(int u=i+1;u<=j-1;u++){
   	  	if(a[u]%x){flag=1;break;}
   	  }
   	  if(a[i]<=a[j]&&!flag){
   	  	counts++;
   	  }
   }
	cout<<counts<<endl;
}
