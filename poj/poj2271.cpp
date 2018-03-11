#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main(){
	char s[100];
	int len=0;
 //	freopen("1.txt","r",stdin);
	while(scanf("%s",s)!=EOF){
		if(strcmp(s,"<br>")==0){ cout<<endl; len=0;}
		else if(strcmp(s,"<hr>")==0){
			if(len)
			cout<<endl;
			len=0;
			cout<<"--------------------------------------------------------------------------------"<<endl;
		}
		else{
			if(!len)  
            {  
                printf("%s",s);  
                len+=strlen(s)+1;  
            }  
            else if(len+strlen(s)<=80)  
            {  
                printf(" %s",s);  
                len+=strlen(s)+1;  
            }  
            else   
            {            
                len=strlen(s)+1; 
				cout<<endl; 
                printf("%s",s);  
            }  
        }
        memset(s,0,sizeof(s));
    }
}
