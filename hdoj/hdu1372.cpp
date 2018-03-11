#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int map[9][9];
int dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int si,sj,ei,ej;
int ans;
void dfs(int si,int sj,int move)
{
	if(si == ei && sj == ej)
		return ;

	for(int i=0;i<8;i++)
	{
		int ti,tj;
		ti = si + dir[i][0];
		tj = sj + dir[i][1];
		if(ti>=1&&ti<=8&&tj>=1&&tj<=8 && map[ti][tj]>move+1)
		{
			map[ti][tj] = move+1;	
			dfs(ti,tj,move+1);		
		}
	}
	return ;	
}
int main()
{
	string a,b;	
	while(cin >> a >> b)
	{
		si = a[0]-'a'+1;
		sj = a[1]-'0';
		ei = b[0]-'a'+1;
		ej = b[1]-'0';
		
		for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
	 		map[i][j] = 1e10;
		
		map[si][sj] = 0;
		ans = 1e10;
		dfs(si,sj,0);
	
		cout << "To get from " << a << " to " << b << " takes " << map[ei][ej] 
		<< " knight moves." << endl;
	
	}
}
