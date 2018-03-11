#include<stdio.h>
#include<string.h>
int M,N;
int map[20][20];
int vis[20][20];  //����ÿһ��ķ�ת����
int t[20][20];   //��ʱ�������������м���
int d[4][2]={0,-1,-1,0,0,1,1,0};
int cnt;
void Flip(int i,int j){       //��ת
	cnt++;                 //������1
	t[i][j]=!t[i][j];      //�ȷ�ת�Լ�
	vis[i][j]=1;
	for(int k=0;k<4;k++){    //��ת���������ĸ�����ĸ���
		int x=i+d[k][0];
		int y=j+d[k][1];
		if(x<0||y<0||x>=N||y>=M)   //Խ���ж�
			continue;
		t[x][y]=!t[x][y];     //��ת
	}
}
bool Judge(int num){    //���ڵ�һ�е�ÿһ�ַ�ת������ж��Ƿ��ܲ�������ȫ��תΪ0�Ľ��
	int i,j;
	cnt=0;       
	memcpy(t,map,sizeof(t));     //��ʼ����ʱ����
	for(i=0;i<M;i++){            //��������˶�����ѹ�������磬j��0��3����ô1 << i�Ķ����ƾ���0001,0010,0100,1000
		if(num&(1<<i)){      //����num��Ӧ�Ķ�������Ϊ1��ÿһλ����Ӧ�÷�ת
			Flip(0,i);        //���ĳһλΪ1���ͷ�ת��һ�е����λ��
		}
	}
	for(i=0;i<N-1;i++){        //��һ�з�ת֮��,�ڶ��е������ڶ��еķ�ת(��������˵��ԭ��ȥ��ת)
		for(j=0;j<M;j++){
			if(t[i][j]==1)
				Flip(i+1,j);
		}
	}
	for(i=0;i<M;i++){        //��Ϊÿһ�е�1����������һ�и㶨���������һ��û����һ�У�����ֻ��Ҫ�������һ������ǲ���ȫ0�Ϳ�����
		if(t[N-1][i])return false;
	}
	return true;
}
int main()
{
	int i,j;
	while(scanf("%d %d",&N,&M)!=EOF){
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				scanf("%d",&map[i][j]);
			}
		}
		int step=N*M+1;         //��ʼ��  
		int p=-1;              //step�����ٵķ�ת������p��ڼ��εķ�ת��������
		for(i=0;i<(1<<M);i++){      //i��ʾһ����������������ö�ٵ�һ�еĸ��ֲ�ͬ��������0001����ֻ�����һ��
			if(Judge(i)&&cnt<step){     //����ҵ�һ�ֿ��ܲ������õĲ������ٵĻ����������ַ��� 
				step=cnt;
				p=i;
			}
		}
		memset(vis,0,sizeof(vis));      
		if(p>=0){           //����ҵ��ľ������ٵķ�����ģ��һ�飬Ȼ�����  
			Judge(p);
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					if(j==M-1)printf("%d\n",vis[i][j]);
					else printf("%d ",vis[i][j]);
				}
			}
		}
		else printf("IMPOSSIBLE\n");     //������ʹ����ȫ��תΪ0
	}
	return 0;
}




/*#include<iostream>
#include<cstring>
using namespace std;
int ans[1000][1000];
int vis[1000][1000];
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++) cin>>ans[i][j];
		 memset(vis,0,sizeof(vis));
		 for(int i=1;i<n;i++){
		 	for(int j=0;j<m;j++){
		 		if(ans[i-1][j]==1){
		 			ans[i-1][j]=!ans[i-1][j];
		 			ans[i][j-1]=!ans[i][j-1];
		 			ans[i+1][j]=!ans[i+1][j];
		 			ans[i][j+1]=!ans[i][j+1];
		 			ans[i][j]=!ans[i][j];
		 			vis[i][j]=1;
				 }
			 }
		 }
		 int f=0;
		 for(int i=0;i<n;i++)
		    for(int j=0;j<m;j++){
		    	if(ans[i][j]==1){
		    		f=1;break;
				}
			}
		if(f) cout<<"IMPOSSIBLE"<<endl;
		else{
			 for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++) {
		 	if(j==m-1) cout<<vis[i][j]<<endl;
		 	else cout<<vis[i][j]<<" ";
		 }
	
		}
	   
	}
}*/
