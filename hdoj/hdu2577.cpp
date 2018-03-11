#include<bits/stdc++.h>
using namespace std;
char s[1050];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int sum=0;
		int lest=0;
		memset(s,0,sizeof(s));
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='A'&&s[i]<='Z'){
	            if(lest<=1)
				sum++;
	            lest++;
				}
				else{
					if(lest>1&&i+1<strlen(s)){
						if(s[i+1]>='a'&&s[i+1]<='z') lest=0;
						else sum++;
					}
					else lest=0;
				}
				
			}
		printf("%d\n",sum+strlen(s));
	}
}
