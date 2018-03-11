#include<iostream>
#include<math.h>
using namespace std;
double a[205][205];
int main(){
	int t,m,n,i,j;
	a[0][0]=0;
	a[1][0]=sqrt(2.0)+1;
	a[0][1]=1.00;
	for(i=2;i<205;i++) {
		a[0][i]=a[0][i-1]+sqrt(2.0)*(i-1)+sqrt(i*i+(i-1)*(i-1));	
	}
	for(i=2;i<205;i++)
	a[i][0]=a[i-1][0]+i*sqrt(2.0)+sqrt(i*i+(i-1)*(i-1));
	for(i=1;i<205;i++){
			for(j=1;j<=204-i;j++){
		a[i][j]=a[i-1][j+1]+sqrt(2.0);
	}
}
	cin>>t;
	int x1,x2,y1,y2;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		printf("%.3lf\n",fabs(a[x1][y1]-a[x2][y2]));
	}
}
