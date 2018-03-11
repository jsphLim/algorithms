#include<bits/stdc++.h>
using namespace std;
int que[16];
int nhh[16]={0};
int cnt,i,j,num,n;
bool check(int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(abs(k-i)==abs(que[k]-que[i])||que[k]==que[i])
			return false;
	}
	return true;
}
void dfs(int a)
{
	int i;
	if(a>num)
		cnt++;
	else
		for(i=1;i<=num;i++)
		{
			que[a]=i;
			if(check(a))
				dfs(a+1);
		}
}
int main(){
	for(i=1;i<=10;i++){
		num=i;
		cnt=0;
		dfs(1);
		nhh[i]=cnt;
	}
	while(cin>>n,n){
		cout<<nhh[n]<<endl;
	}
	
}
