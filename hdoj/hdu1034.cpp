#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n;
bool check(){
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]) return true;
	}
	return false;
}
int main(){
	int i,j,cnt=0;
	int t;
	while(scanf("%d",&n),n){
		cnt=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		while(check()){
		int y=a[n-1]/2;
            for(i=n-1;i>0;i--)
            {            
                a[i]=a[i]/2+a[i-1]/2;
                if(a[i]%2)
                    a[i]++;
            }
            a[0]=a[0]/2+y;
            if(a[0]%2)
                a[0]++;
		cnt++;
	}
	cout<<cnt<<" "<<a[0]<<endl;
}
}
