#include<bits/stdc++.h>
using namespace std;
struct st{
	char num[100];
	int sum;
}sd[1200]; 
bool cmp(st x,st y){
	if(x.sum!=y.sum){
		return x.sum>y.sum;
	}
	if(x.sum==y.sum){
	return strcmp(x.num,y.num)<0;
}
}
int score[30];
int main(){
	int stnum,tnum,i,pass_score,ti,scores,sums=0;
	while(scanf("%d",&stnum),stnum){
		int k=0;
		memset(score,0,sizeof(score));
		scanf("%d%d",&tnum,&pass_score);
		for(i=1;i<=tnum;i++) scanf("%d",&score[i]);
		for(i=0;i<stnum;i++){
			scanf("%s",&sd[i].num);
			scanf("%d",&ti);
			for(int j=0;j<ti;j++) {
				scanf("%d",&scores);
				sums+=score[scores];
			}
			sd[i].sum=sums;
			if(sums>=pass_score) k++;
			sums=0;
		}
		sort(sd,sd+stnum,cmp);
		cout<<k<<endl;
		for(i=0;i<k;i++){
			cout<<sd[i].num<<" "<<sd[i].sum<<endl;
	}
}
}
