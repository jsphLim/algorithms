#include<iostream>

using namespace std;

int a[2][2];
int b[2][2];

int main(){
	int t;
	//freopen("1.txt","r",stdin);
	cin>>t;

	int cnt=0;
	while(t--){

		for(int i=0;i<2;i++) 
		for(int j=0;j<2;j++)
		cin>>a[i][j];
		for(int i=0;i<2;i++) 
		for(int j=0;j<2;j++)
		cin>>b[i][j];
	int flag=0;
	if(a[0][0]==b[0][0]&&a[0][1]==b[0][1]&&a[1][0]==b[1][0]&&a[1][1]==b[1][1]) flag=1;

	if(a[0][0]==b[0][1]&&a[0][1]==b[1][1]&&a[1][1]==b[1][0]&&a[1][0]==b[0][0]) flag=1;
	if(a[0][0]==b[1][1]&&a[0][1]==b[1][0]&&a[1][1]==b[0][0]&&a[1][0]==b[0][1]) flag=1;
	if(a[0][0]==b[1][0]&&a[0][1]==b[0][0]&&a[1][1]==b[0][1]&&a[1][0]==b[1][1]) flag=1;
		
	
		if(flag){
		cout<<"Case #"<<++cnt<<": POSSIBLE"<<endl;
		}
		else{
			cout<<"Case #"<<++cnt<<": IMPOSSIBLE"<<endl;
		}

	}
}