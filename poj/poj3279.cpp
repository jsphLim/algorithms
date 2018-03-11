#include<stdio.h>
#include<string.h>
int M,N;
int map[20][20];
int vis[20][20];  //保存每一格的翻转次数
int t[20][20];   //临时数组用来保存中间结果
int d[4][2]={0,-1,-1,0,0,1,1,0};
int cnt;
void Flip(int i,int j){       //翻转
	cnt++;                 //次数加1
	t[i][j]=!t[i][j];      //先翻转自己
	vis[i][j]=1;
	for(int k=0;k<4;k++){    //翻转上下左右四个方向的格子
		int x=i+d[k][0];
		int y=j+d[k][1];
		if(x<0||y<0||x>=N||y>=M)   //越界判断
			continue;
		t[x][y]=!t[x][y];     //翻转
	}
}
bool Judge(int num){    //对于第一行的每一种翻转情况，判断是否能产生矩阵全翻转为0的结果
	int i,j;
	cnt=0;       
	memcpy(t,map,sizeof(t));     //初始化临时数组
	for(i=0;i<M;i++){            //这里采用了二进制压缩，例如，j从0到3，那么1 << i的二进制就是0001,0010,0100,1000
		if(num&(1<<i)){      //对于num对应的二进制数为1的每一位，都应该翻转
			Flip(0,i);        //如果某一位为1，就翻转第一行的这个位置
		}
	}
	for(i=0;i<N-1;i++){        //第一行翻转之后,第二行到倒数第二行的翻转(按上面我说的原则去翻转)
		for(j=0;j<M;j++){
			if(t[i][j]==1)
				Flip(i+1,j);
		}
	}
	for(i=0;i<M;i++){        //因为每一行的1都可以由下一行搞定，但是最后一行没有下一行，所以只需要考察最后一行最后是不是全0就可以了
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
		int step=N*M+1;         //初始化  
		int p=-1;              //step存最少的翻转步数，p存第几次的翻转步数最少
		for(i=0;i<(1<<M);i++){      //i表示一个二进制数，用来枚举第一行的各种不同翻法，如0001就是只翻最后一个
			if(Judge(i)&&cnt<step){     //如果找到一种可能并且所用的步数更少的话，记下这种翻法 
				step=cnt;
				p=i;
			}
		}
		memset(vis,0,sizeof(vis));      
		if(p>=0){           //最后找到的就是最少的翻法，模拟一遍，然后输出  
			Judge(p);
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					if(j==M-1)printf("%d\n",vis[i][j]);
					else printf("%d ",vis[i][j]);
				}
			}
		}
		else printf("IMPOSSIBLE\n");     //不可能使矩阵全翻转为0
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
