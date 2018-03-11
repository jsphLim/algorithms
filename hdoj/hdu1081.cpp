#include<iostream>
#include<stack>
int mat[100][100];
int maxx[100][100];
using namespace std;
int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		scanf("%d",&mat[i][j]);
		int ret,sum;
		for(i=0;i<n;i++)
		for(maxx[i][j=0]=0;j<n;j++)
		   maxx[i][j+1]=maxx[i][j]+mat[i][j];
		for(ret=mat[0][j=0];j<n;j++)
		for(int k=j;k<n;k++)
		for(sum=0,i=0;i<n;i++)
		  sum=(sum>0?sum:0)+maxx[i][k+1]-maxx[i][j],ret=(sum>ret?sum:ret);
		  
		  cout<<ret<<endl;
	}
}
