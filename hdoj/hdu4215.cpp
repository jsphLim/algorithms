#include<bits/stdc++.h>
using namespace std;
int ans[1000]={0,1,1,2,2,4,5,5,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,9,9,9};
int main(){
	int t,n;
	cin>>t;
	int kcase=1;
	while(t--){
	     cin>>n;
        if(n>29) printf("Case %d: %d\n",kcase++,10);
	    else printf("Case %d: %d\n",kcase++,ans[n]);
	  }

}
//打表找规律 
/*#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	int t,n=0;
	cin>>t;
	int e[1000];
	int f[1000];
	int kcase=1;
	while(t--){
		n++;
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		int sum=0,cnt=0,sumx=0;
		for(int i=1;i<=n;i++){
			   for(int j=1;j<=i;j++){
			if(gcd(i,j)==1) e[i]++;
			if(i%j==0) f[i]++;
		}	
	} 
		for(int i=2;i<=n;i++){
			e[i]+=e[i-1];
			f[i]+=f[i-1];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(e[j]-e[i-1]==f[j]-f[i-1]){
					cnt++;
				}
			}
		}
		printf("Case %d: %d\n",kcase++,cnt);
	  }

}*/
