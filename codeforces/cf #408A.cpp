#include<bits/stdc++.h>
using namespace std;
int ans[1000];
int main(){
	int k,pos,tot;
	int minn=9999999;
	scanf("%d%d%d",&k,&pos,&tot);
	for(int i=1;i<=k;i++){
		scanf("%d",&ans[i]);
		if(ans[i]<=tot&&i!=pos&&ans[i]!=0) minn=min(minn,abs(i-pos));
	} 
	cout<<minn*10<<endl;
}
