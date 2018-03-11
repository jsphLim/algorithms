#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[12],b[12],c[12],d[12];
	int n;
	while(cin>>a>>b){
		scanf("%d",&n);
		cout<<a<<" "<<b<<endl;
		while(n--){
			cin>>c>>d;
			if(strcmp(a,c)==0){
			printf("%s %s\n",d,b);
			memset(a,0,sizeof(a));
			strcpy(a,d); 
		}
		else if(strcmp(a,d)==0){
				printf("%s %s\n",b,c);
				memset(a,0,sizeof(a));
			strcpy(a,c);  
		}
		else if(strcmp(b,c)==0){
			printf("%s %s\n",a,d);
			memset(b,0,sizeof(b));
		strcpy(b,d); 
		}
		else if(strcmp(b,d)==0){
			printf("%s %s\n",a,c);
			memset(b,0,sizeof(b));
		strcpy(b,c); 
		}
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	}
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
} 
}
