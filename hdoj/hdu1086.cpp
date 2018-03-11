#include<bits/stdc++.h>
using namespace std;
struct Point{
	double x,y;
};
Point o[105];
Point t[105];
double mult(Point a, Point b, Point c)  
{  
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);  
}  
  
//aa, bb为一条线段两端点 cc, dd为另一条线段的两端点 相交返回true, 不相交返回false  
bool intersect(Point aa, Point bb, Point cc, Point dd)  
{  
    if ( max(aa.x, bb.x)<min(cc.x, dd.x) )  
    {  
        return false;  
    }  
    if ( max(aa.y, bb.y)<min(cc.y, dd.y) )  
    {  
        return false;  
    }  
    if ( max(cc.x, dd.x)<min(aa.x, bb.x) )  
    {  
        return false;  
    }  
    if ( max(cc.y, dd.y)<min(aa.y, bb.y) )  
    {  
        return false;  
    }  
    if ( mult(cc, bb, aa)*mult(bb, dd, aa)<0 )  
    {  
        return false;  
    }  
    if ( mult(aa, dd, cc)*mult(dd, bb, cc)<0 )  
    {  
        return false;  
    }  
    return true;  
}  
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&o[i].x,&o[i].y,&t[i].x,&t[i].y);
		}
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				if(intersect(o[i],t[i],o[j],t[j])) cnt++;
			}
			
		cout<<cnt<<endl;
	}
}
