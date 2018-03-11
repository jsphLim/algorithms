#include<iostream>
#include<string.h>
using namespace std;
int d[610];
int dir(string str, int *a)
{
    if (str=="forward")
    {
        d[0] = a[0];d[1] = a[1];d[2] = a[2]; d[3] = a[3]; d[4] = a[4];d[5] = a[5];
    }
    else if (str=="back")
    {
        d[0] = a[1];d[1] = a[0]; d[2] = a[3]; d[3] = a[2]; d[4] = a[4];  d[5] = a[5];      
    }
    else if (str=="left")
    {
        d[0] = a[2]; d[1] = a[3];d[2] = a[1]; d[3] = a[0]; d[4] = a[4]; d[5] = a[5]; 
    }
    else if (str=="right")
    {
        d[0] = a[3];  d[1] = a[2];d[2] = a[0];d[3] = a[1]; d[4] = a[4];d[5] = a[5];
    }
    else if (str=="up")
    {
        d[0] = a[4]; d[1] = a[5];d[2] = d[2]; d[3] = a[3]; d[4] = a[1]; d[5] = a[0];  
    }
    else if (str=="down")
    {
        d[0] = a[5]; d[1] = a[4];d[2] = a[2];d[3] = a[3];d[4] = a[0];d[5] = a[1];
    }
    return 0;
}
int change[60]={0,3,4,1,2,5};
int main(){
	int t;
	int n;
	
	int step;
	cin>>t;
	while(t--){
		change[0]=0;change[1]=3;change[2]=4;change[3]=1;change[4]=2;change[5]=5;
		memset(d,0,sizeof(d));
		string s;
		int x=0,y=0,z=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s>>step;
			dir(s,change);
			for(int j=0;j<6;j++){change[j]=d[j];}
				if(d[0]==1) y+=step;
				else if(d[0]==2) z+=step;
				else if(d[0]==0) x+=step;
				else if(d[0]==3) x-=step;
				else if(d[0]==4) y-=step;
				else if(d[0]==5) z-=step;
				
		}
		cout<<x<<" "<<y<<" "<<z<<" "<<d[0]<<endl;
	}
}
		
	
	
