#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
		int sum=0;
		while(a<c){
		a=a+a*b/100.0;
		sum++;
	}
	cout<<sum<<endl;
	}
}
