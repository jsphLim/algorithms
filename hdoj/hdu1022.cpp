#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[1000];
	char b[1000];
	int c[1000];
	int n;
	while(scanf("%d",&n)!=EOF){
		int flag=0,k=0;
		scanf("%s",a);
		scanf("%s",b);
		stack<char> s;
		int i=0,j=0;
		while(i<n){
			if(s.empty()||s.top()!=b[i]&&j<n){
				s.push(a[j]);
				j++;
				c[k++]=1;
			}
			else {
			if(s.top()==b[i]){
				c[k++]=2;
				s.pop();
				i++;
			}
			else break;
		}
	}
			if(s.empty()){
				cout<<"Yes."<<endl;
				for(i=0;i<k;i++){
					if(c[i]==1) cout<<"in"<<endl;
					else if(c[i]==2) cout<<"out"<<endl;
				}
			}
			else cout<<"No."<<endl;
			cout<<"FINISH"<<endl;
	}
}
		
