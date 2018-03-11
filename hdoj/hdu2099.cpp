
#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,k;
	int flag[100];;
	while(scanf("%d%d",&n,&m)!=0&&(n||m))
	{   n*=100;k=0;
	    for(i=0;i<10;i++){
	    	if((n+i)%m==0){
	    		flag[k++]=i;
			}
		}
	    for(i=10;i<=99;i++){
	    	if((n+i)%m==0){
	    		flag[k++]=i;
			}
		}
		for(i=0;i<k-1;i++){
			if(flag[i]<10) cout<<0<<flag[i]<<" ";
			else cout<<flag[i]<<" ";
		}
		if(flag[k-1]<10) cout<<0<<flag[k-1]<<endl;
		else cout<<flag[k-1]<<endl;
}
}
