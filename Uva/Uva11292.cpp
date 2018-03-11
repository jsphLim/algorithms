#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 20005;
int A[maxn],B[maxn];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)&&(m+n)){
		for(int i=0;i<n;i++) scanf("%d",&A[i]);
		for(int i=0;i<m;i++) scanf("%d",&B[i]);
		sort(A,A+n);
		sort(B,B+m);
		int k=0,i=0,sum=0,f=0;
		while(k<m){
			if(A[i]<=B[k]){
				sum+=B[k];
			if(++i==n) break;
			}
			k++;
		}
		if(i<n) cout<<"Loowater is doomed!"<<endl;
		else cout<<sum<<endl;
	}
} 
