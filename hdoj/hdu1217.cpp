#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
double mp[33][33],lv;
int i,j,k,l,m,n,x,y;
char c[100],s[100];
void floyd()
{
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	for(k=0;k<n;k++)
	if(mp[j][k]<mp[j][i]*mp[i][k])
	mp[j][k]=mp[j][i]*mp[i][k];
}
int main()
{
	int kcase=1;
	map<string,int> ma;
	while(scanf("%d",&n),n){
		int num=0;
		memset(mp,0,sizeof(mp));
		for(i=0;i<n;i++){
			memset(c,0,sizeof(c));
			scanf("%s",c);
			ma[c]=num++;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			memset(c,0,sizeof(c));
			memset(s,0,sizeof(s));
			scanf("%s%lf%s",c,&lv,s);
			mp[ma[c]][ma[s]]=lv;
		}
		floyd();
		for(i=0;i<n;i++)
		if(mp[i][i]>1)
		break;
		if(i<n) printf("Case %d: Yes\n",kcase++);
		else printf("Case %d: No\n",kcase++);
	}
}
