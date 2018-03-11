#include<stdio.h>
#include<string.h>

bool map[3001][3001];
int main(){
	int t,n;
	//freopen("1.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
	memset(map,0,sizeof(map));
	   scanf("%d",&n);
	   for(int i=0;i<n-1;i++)
	   	for(int j=i+1;j<n;j++){
	   		int v;
	   		scanf("%d",&v);
	   		if(v){
	   		map[i][j]=true;	
	   		}
	   		
	   	}
	 int flag=0;
	 int cnt1=0;
	 int cnt2=0;
	 for(int i=0;i<n-1;i++){
	 for(int j=i+1;j<n;j++){
	 	if(!map[i][j]) cnt1++;
	 	if(map[i][j]) cnt2++; 
	 	 if(cnt1>=3||cnt2>=3) flag=1;
	 }
	 cnt1=cnt2=0;
	}
	 //cout<<cnt1<<" "<<cnt2<<endl;

  	   if(flag) printf("Bad Team!\n");
  	   else printf("Great Team!\n");
	}
}