#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define eps 10e-6
int n;
struct line{
	double x1;
	double y1;
	double x2;
	double y2;
	//line(double x,double y,double xx,double yy) { x1=x; y1=y; x2=xx; y2=yy;}
	  
};
line seq[105];
double distance(double x,double y,double x1,double y1){
	return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

double cross(double x1,double y1,double x2,double y2,double x,double y){
	return (x1-x)*(y2-y)-(x2-x)*(y1-y);
}

bool judge(double x1,double y1,double x2,double y2){
	if(distance(x1,y1,x2,y2)<eps) return false;
	for(int i=0;i<n;i++){
		if(cross(x1,y1,x2,y2,seq[i].x1,seq[i].y1)*cross(x1,y1,x2,y2,seq[i].x2,seq[i].y2)>eps) return false;
	}
	return true;
}

int main(){
		int t;
	//	freopen("1.txt","r",stdin);
		cin>>t;
		while(t--){
			cin>>n;
			int flag=0;
			for(int i=0;i<n;i++) cin>>seq[i].x1>>seq[i].y1>>seq[i].x2>>seq[i].y2;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
			if(judge(seq[i].x1,seq[i].y1,seq[j].x2,seq[j].y2)||judge(seq[i].x1,seq[i].y1,seq[j].x1,seq[j].y1)||judge(seq[i].x2,seq[i].y2,seq[j].x1,seq[j].y1)||judge(seq[i].x2,seq[i].y2,seq[j].x2,seq[j].y2)){
				flag=1;break;
			}
			}
		}
			if(flag) cout<<"Yes!"<<endl;
			else cout<<"No!"<<endl;
	}
}

