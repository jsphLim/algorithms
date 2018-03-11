#include<stdio.h>
#include<string.h>
char s[100][100];
int main(){
	int x,y,i,j;
	while(scanf("%d%d",&x,&y)!=EOF){
		s[0][0]='+';
		s[0][x+1]='+';
		s[y+1][0]='+';
		s[y+1][x+1]='+';
		for(i=1;i<=x;i++){
			s[0][i]='-';
			s[y+1][i]='-';
		}
		for(i=1;i<=y;i++){
			s[i][0]='|';
			s[i][x+1]='|';
		}
		for(i=0;i<=y+1;i++)
		for(j=0;j<=x+1;j++){
			if(s[i][j]!=0){
				printf("%c",s[i][j]);
				if(j==x+1) printf("\n");}
				else printf(" ");
		}
		memset(s,0,sizeof(s));
		printf("\n");
	}
}
