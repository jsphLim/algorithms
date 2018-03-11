#include<iostream>
using namespace std;
struct node{
	int U;
	int L;
	int sum;
};

int cal(int x,int y,int x1,int y1,int x2,int y2){
	int dirx1=x1-x;
	int diry1=y1-y;
	int dirx2=x2-x;
	int diry2=y2-y;
	int cals = dirx1*diry2-dirx2*diry1;
	if(cals>0) return 1;
	else return -1;
}
	
int main(){
       int n,m,x1,y1,x2,y2;
       int xj,yj;
       
       while(cin>>n,n){
	   int cas=0;
	   cin>>m>>x1>>y1>>x2>>y2;
       	node partition[5005];
       	partition[0].U=partition[0].L=x1;
       	partition[n+1].U=partition[n+1].L=x2;
       	partition[0].sum=partition[n+1].sum=0;
       	for(int i=1;i<=n;i++) {
       		cin>>partition[i].U;
       		cin>>partition[i].L;
       		partition[i].sum=0;
       	}
       	for(int i=0;i<m;i++){
       		cin>>xj>>yj;
       		for(int j=1;j<=n+1;j++){
       			if(cal(xj,yj,partition[j].U,y1,partition[j].L,y2)<0){
       				partition[j-1].sum++;
       				break;
       			}
       		}
       	}
       	for(int i=0;i<=n;i++){
       		cout<<cas++<<": "<<partition[i].sum<<endl;
       	}
       	cout<<endl;
       }
}