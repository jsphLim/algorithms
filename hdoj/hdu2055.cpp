#include<stdio.h>
#include<math.h>
#include<string.h>
char a[1000005],b[1000005];
int main(){
	int i;
	while(scanf("%s%s",a,b)!=EOF){
		int flag=0;
		int len1=strlen(a);
		int len2=strlen(b);
	    for(i=0;i<len1;i++){
	    	if(a[i]=='.') {
	    	flag=1;	break;
			}
		}
		if(flag){
			for(int i=len1-1;i>=0;i--){
				if(a[i]=='0') a[i]='\0';
				else break;
				len1--;
			}
		if(a[len1-1]=='.') a[len1-1]='\0';
		}
		flag=0;
		//b
		for(i=0;i<len2;i++){
	    	if(b[i]=='.'){
	    		flag=1;break;
			} 
		}
		if(flag){
			for(int i=len2-1;i>=0;i--){
				if(b[i]=='0') b[i]='\0';
				else break;
				len2--;
			}
		if(b[len2-1]=='.') b[len2-1]='\0';
		}
		if(strcmp(a,b)==0) printf("YES\n");
		else printf("NO\n");	
		
	}
}
