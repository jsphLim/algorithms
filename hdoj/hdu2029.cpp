#include<stdio.h>
#include<string.h>
using namespace std;
char a[100];
char b[100];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		strcpy(b,a);
		strrev(b);
		if(!strcmp(a,b)) printf("yes\n");
		else printf("no\n");
	}
}
