#include<stdio.h>
#include<string.h>
int main(){
	char arr[1000];
	while(gets(arr)){
        if(strcmp(arr,"ENDOFINPUT")==0)break;
		if(strcmp(arr,"START")==0)continue;
		if(strcmp(arr,"END")==0)continue;
		for(int i=0;i<strlen(arr);i++){
			 if(arr[i]>='A'&&arr[i]<='E') arr[i]+=21;
            else if(arr[i]>'E'&&arr[i]<='Z') arr[i]-=5;
		}
		puts(arr);
	}
} 
