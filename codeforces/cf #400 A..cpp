#include<bits/stdc++.h>
using namespace std;
int que[100005];
int main(){
	int n,i;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++) scanf("%d",&que[i]);
		sort(que,que+n);
		int sum=0;
		for(i=0;i<n;i++){
			if(que[i]==que[0]||que[i]==que[n-1]) sum++;
		}
		cout<<n-sum<<endl;
	}
}
