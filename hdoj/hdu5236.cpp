#include<stdio.h>
#include<string.h>
using namespace std;
int a[1000005];
int main(){
	int modd=1000000007;
	char s[1000005];
	scanf("%s",s);
	int cnt_b=0;
	int cnt_a=0;
	for(int i=strlen(s)-1;i>=0;i--){
		//printf("%c\n",s[i]);
		if(s[i]=='b'){
			cnt_b++;
		}
		if(s[i]=='a'){
			a[cnt_a++]=cnt_b;
			//printf("%d\n",a[cnt_a-1]);
		}
	}
	int ans=0;
	for(int i=0;i<cnt_a;i++){
		ans+=a[i];
		int dengcha=((cnt_a-i-1+1)*(cnt_a-i-1)/2);
	//	printf("%d\n",dengcha);
		ans=(ans+dengcha*a[i])%modd;
	}
	printf("%d\n",ans%modd);
}
