#include<cstdio>
#include<algorithm>
using namespace std;
double a[10000];
int main(){
	int t,m,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&m);
		for(i=0;i<m;i++) scanf("%lf",&a[i]);
		sort(a,a+m);
		printf("%.2f\n",a[m-1]);
	}
} 
